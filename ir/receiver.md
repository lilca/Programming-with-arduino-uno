# リモコン受信機
***(正確さは保証しかねる。ご参考程度に)***
## リモコンの仕様
- 回路図

```
受信機
                / / 赤外線
               V V                              Monitor
          +----------+  Vout  +----------+    +--------------------------------------------------------------------+
VCC o-----| 赤外線受信 |--------| pin8     |    | Code = 555AF148688B.                                               |
GND o-----| モジュール |        |          | => | Bit data[49] = 010101010101101011110001010010000110100010001011    |
          +----------+        | arduino  |    |   :                                                                |
                              |   uno v3 |    |   :                                                                |
                              +----------+    +--------------------------------------------------------------------+
```

- 型番

|パラメータ|値|
|:-|:-|
|赤外線受信モジュール|型番不明（中国製）|
|電圧範囲|2.4 - 5.0[V]|
|周波数|38[kHz]|

|パラメータ|値|
|:-|:-|
|赤外線LED|TLN115A|


- 受信モジュールのピンアサイン

|足番||
|:-|:-|
|1|Vout|
|2|GND|
|3|VCC|

```
+-----+
| up  |
+-----+
  \_/
|  |  |
|  |  |
1  2  3
```

# リモコンコード（参考文献(1)）
|ボタン名|コード(b7..b0)|出力結果(b0..b7)|
|:-|:-|:-|
|電源|aa 5a 8f 12 16 d1|aa a5 f8 21 61 1d| 55 5a f1 48 68 8b|
|画面サイズ|aa 5a 8f 12 d5 21|aa a5 f8 21 5d 12|55 5a f1 48 ab 84|

　※シャープAQUOSテレビの場合、周期 = 425[us]（参考文献(4)）

　※コードは表記もデータの送受信もLSB First

# 処理フロー

# 参考文献

(1): [7. メーカー純正リモコンのコードー赤外線リモコンの信号定義データの合成 1.3.1 ドキュメント](http://shrkn65.nobody.jp/remocon/database.html)

(2): [AQUOSリモコンの信号解析をしましたースイッチ工作室](https://ameblo.jp/ohanashi555/entry-11882737031.html)

(3): [REGZAのリモコンコード解析(CT-90352)](http://www.gatelink.co.jp/hw/etc/regzaremo/index.html)

(4): [赤外線リモコンの通信フォーマット](http://elm-chan.org/docs/ir_format.html)

(5): [赤外線リモコンー東工大おやぢ](https://ameblo.jp/aoijf2/entry-11261684880.html)

(6): [真夏のArduinoーヨンマルキュー](https://4009.jp/post/2016-08-23-summer/)

(7): [安直に赤外線回路を作る](https://qiita.com/nanbuwks/items/57e6a6112d0459ca7810)
