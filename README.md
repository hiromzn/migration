# migration
source code migration

# 調査

## gcc

- gcc log

  - 3.7 Options to Control Diagnostic Messages Formatting
    - https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Message-Formatting-Options.html
    - fdiagnostics-format=FORMAT
      - json / text

  - 3.8 Options to Request or Suppress Warnings
    - https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#Warning-Options

    - Wall
    - Wextra

- option

  - マクロの使用とデバッグに関するオプション
    - -Dmacro, -Dmacro=value [知ってると便利]
      臨時にマクロを定義する。
    - -Umacro
      - 臨時にマクロを未定義にする。
    - -E
      - マクロの展開だけをする。
    - -C (with -E)
      - マクロの展開だけを実行：コメントは残す。
    - -P (with -E)
      - マクロの展開だけを実行：#line 行を生成しない。
    - -M (with -E)
      - ソースに include されているファイル名を表示
    - -MM (with -E)
      - ソースに include されているファイル名を表示するが、システムが最初からincludeしているものは除く。
    - -dM (with -E)
      - ソース中で一度でも参照されたマクロ定義を表示
    - -dD (with -E)
      - ソース中のマクロ定義、およびプロトタイプ定義を表示
