import subprocess
import sys
import random
import re
import time
import os

def run_test(n, limit):
    # Generate n random numbers
    # Using a large range to minimize duplicates, though duplicates are usually allowed
    nums = [str(random.randint(1, 100000)) for _ in range(n)]
    
    # Run PmergeMe
    try:
        # Passing arguments as a list avoids shell expansion limits
        result = subprocess.run(["./PmergeMe"] + nums, capture_output=True, text=True, timeout=30)
    except subprocess.TimeoutExpired:
        print(f"❌ N={n}: Timeout (took > 30s)")
        return False

    if result.returncode != 0:
        print(f"❌ N={n}: Error (Return code {result.returncode})")
        return False

    # Search for comparison count in output
    # Matches "Comparisons: 123", "count: 123", "cmp: 123", etc. case-insensitive
    match = re.search(r"(?:comparisons|operations|count|cmp)[^0-9]*(\d+)", result.stdout, re.IGNORECASE)
    
    if match:
        count = int(match.group(1))
        if count <= limit:
            # Uncomment the line below to see passing tests
            # print(f"✅ N={n}: {count} <= {limit}")
            return True
        else:
            print(f"❌ N={n}: Count {count} > Limit {limit}")
            print(f"   Input: {' '.join(nums)}")
            return False
    else:
        print(f"⚠️  N={n}: Could not find comparison count in output. Make sure to print 'Comparisons: <number>'")
        return False

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 verify_complexity.py <limits_file>")
        print("Example: python3 verify_complexity.py limits.txt")
        sys.exit(1)

    if not os.path.isfile("./PmergeMe"):
        print("❌ Error: './PmergeMe' executable not found.")
        print("👉 Please run 'make' to compile your project first.")
        sys.exit(1)

    limits_file = sys.argv[1]
    print(f"Reading limits from {limits_file}...")
    
    try:
        with open(limits_file, 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"❌ Error: '{limits_file}' not found.")
        print("👉 Please run 'python3 generate_limits.py' to create it.")
        sys.exit(1)

    print(f"Found {len(lines)} test cases. Starting benchmark...")
    
    failures = 0
    for i, line in enumerate(lines):
        parts = line.strip().split()
        if len(parts) < 2: continue
        
        n = int(parts[0])
        limit = int(parts[1])
        
        if not run_test(n, limit):
            failures += 1
            # break # Uncomment to stop on first failure
        
        if (i + 1) % 100 == 0:
            print(f"Progress: {i + 1}/{len(lines)} tests completed...")

    if failures == 0:
        print("\n🎉 All tests passed! Your sorting algorithm is efficient.")
    else:
        print(f"\n💀 {failures} tests failed.")

if __name__ == "__main__":
    main()