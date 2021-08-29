# Led Camp9

## LED-Camp ControllerクラスAPI

以下ではLED-Campの実習に使用するControllerクラスのAPIを中心に説明する。


## 自己位置

### **`Controller::getPosition`**

引数: なし  
返値: Position::PositionValue{float distance, angle}  
振舞: 現在の進んだ距離・角度を格納するPositionValue型変数を返す  

```sh
Position::PositionValue positionValue;
positionValue = Controller::getPosition();
```

### **`Controller::positionReset`**

引数: なし  
返値: なし  
振舞: 走行距離をリセットする  

```sh
controller->positionReset();
```


## モータ制御

### **`Controller::changeDriveMoode`**


引数: Mode mode, int pwmDuty  
返値: なし  
振舞: Mode (FORWARD, BACK, STOP, CW, CCW) のパターンにpwmDutyの回転速度でモータを回転させる  

```sh
controller->changeDriveMode(FORWARD,100);
```

## 距離センサ

```sh
### **`Controller::getRange`**
```
引数: なし  
返値: float  
振舞: 距離センサから取得した値を返す  

```sh
float range;
range = controller->getRange();
```

## ラインセンサ

### **`Controller::getLineValue`**


引数 なし  
返値: LineSensor::LineValue{int left, center, right}  
振舞: ラインセンサの白黒判定（0or1）を格納するLineValue型変数を返す  

```sh
LineSensor::LineValue lineValue;
lineValue = Controller::getLineValue();
```


## カラーセンサ

### **`Controller::getColorValue`**

引数: なし  
返値: struct ColorValue{unsigned int red, green, blue}  
振舞: カラーセンサの読み取る色の値（R,G,B, 0-255）を構造体に入れて返す  

```sh
#include"drivers/includes/ColorSensor.hpp"
...
ColorSensor::ColorValue colorValue;
coLorvalue = controller->getColorValue();
printf("color red = %u", colorValue.red);
```

## 競技会練習用環境へのブロック追加

競技会練習用環境は、初期環境としてLED-Tankと円柱ブロックが1つ存在した状態である。
実際の競技会ではブロック数が7個のためブロックを適宜追加しながらの開発が考えられる。 
以下にブロックの追加方法を示す。

1. webots を起動し、File＞open world から開発用環境(practice.wbt)を選択して開く。

2. webots上の時間が0になっていることを確認、0でなければResetSimurationする（⌘＋Shift＋T　or Ctrl + Shift + T）

3. 左側にあるシーンツリーのSolidを選択し、copy & pasteする
    <p><img src="./doc_imgs/copy_solid.png"/></p>

4. 2つのブロックが重なった状態になっているので見た目で2つあることはわからない。見えているブロックを選択しShiftを押しながら、横にスライドさせる。
    <p><img src="./doc_imgs/solid_slide.png"/></p>

5. 3-4 を繰り返し必要個数だけブロックを生成し保存する。(⌘+Shift+S or Ctrl + Shift + S)