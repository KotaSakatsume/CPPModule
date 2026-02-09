import math

def main():
    filename = "limits.txt"
    print(f"Generating {filename} ...")
    
    val = 0
    with open(filename, "w") as f:
        for n in range(1, 10001):
            val += math.ceil(math.log2(3 * n / 4))
            f.write(f"{n} {val}\n")
            
    print("Done. You can now run: python3 verify_complexity.py limits.txt")

if __name__ == "__main__":
    main()