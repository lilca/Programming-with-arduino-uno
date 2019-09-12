# Arduino ISPを使った書き込み

## 「スケッチ例」から「ArduinoISP」を開き、Arduino Uno rev3に書き込み

## 配線

## プロジェクトフィルダに「avrdude.conf」をプロジェクトフォルダにコピー

## 書き込むスケッチを「コンパイルしたバイナリを出力」でHEXファイルを生成してプロジェクトフォルダへ

## 実行

 <avrdude.exe> -c avrisp -C <avrdude.conf> -P <シリアルポート> -p m328p -b 19200 -u -e -U flash:w:<スケッチのHEXファイル>:a
 /Applications/Arduino.app/Contents/java/hardware/tools/avr/bin/avrdude -c avrisp -C avrdude.conf -P /dev/tty.usbmodem14201 -p m328p -b 19200 -u -e -U flash:w:serial_signal_test.ino.standard.hex:a
