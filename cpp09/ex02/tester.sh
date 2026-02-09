#!/bin/bash

# --- 設定 ---
PROGRAM="./PmergeMe"
NUM_ELEMENTS=${1:-22} # 要素数 (引数で指定可能、デフォルト22)
MIN_VAL=1             # 最小値
MAX_VAL=10000         # 最大値
# ------------

# 実行ファイルがあるか確認
if [ ! -f "$PROGRAM" ]; then
    echo "Error: $PROGRAM が見つかりません。make してください。"
    exit 1
fi

# OSによって乱数生成コマンドを使い分ける (42のMacはjot, Linuxはshuf)
if command -v jot > /dev/null; then
    # macOS / BSD
    ARG=$(jot -r $NUM_ELEMENTS $MIN_VAL $MAX_VAL | tr '\n' ' ')
else
    # Linux
    ARG=$(shuf -i $MIN_VAL-$MAX_VAL -n $NUM_ELEMENTS | tr '\n' ' ')
fi

echo "=========================================="
echo " Running test with $NUM_ELEMENTS elements"
echo "=========================================="
echo "Input: $ARG"
echo "------------------------------------------"

# 実行
$PROGRAM $ARG

echo "------------------------------------------"
# 終了コードのチェック (セグフォ検知など)
if [ $? -eq 0 ]; then
    echo "✅ Execution finished successfully."
else
    echo "❌ Execution Failed (Segfault or Error)."
fi