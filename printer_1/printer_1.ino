#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include "neko_1.h"
#include "neko_2.h"
#include "neko_3.h"
#include "neko_4.h"
#include "neko_5.h"
#include "neko_6.h"
#include "neko_7.h"
#include "neko_8.h"
#include "neko_9.h"
#include "neko_10.h"
#include "neko_11.h"
#include "neko_12.h"
#include "neko_13.h"
#include "neko_14.h"
#include "neko_15.h"
#include "neko_16.h"
#include "neko_17.h"
#include "neko_18.h"
#include "neko_19.h"
#include "neko_20.h"
#include "neko_21.h"


#define TX_PIN 6        //プリンター側は青RX
#define RX_PIN 5        //プリンター側は緑TX、 黄色は繋がない

SoftwareSerial Thermal(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&Thermal);

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String str;

int sei; //性別
int img;

int pr;

bool printed = false;

void setup() {

  Serial.begin(9600);
  Thermal.begin(9600);
  printer.begin();

}

void loop() {
  str = Serial.readStringUntil('\n');// "\n"までprocessingから送られたシリアル通信の文字列を読む

  if (str.indexOf("se=") > -1) { // strに"se="が含まれているかを検索
    sei = str.substring(3).toFloat(); //含まれていたら、3文字目以降を切り出して文字列から数値へと変換
  }

  if (str.indexOf("pr=") > -1 && pr == 0) { // strに"pr="が含まれているかを検索（プリントするフラグとして使用）
    pr = str.substring(3).toFloat();
    print_receipt();

  }
}

void print_receipt() {

  delay(1500); //シリアル通信待ち時間
  printer.write(27);//ESC コマンド
  printer.write(57);//9 文字セット変更
  printer.write(1); //UTF-8(日本語表示)指定
  printer.feed(3);
  pr = 0;

  if (sei == 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21) {
    printer.justify('C');   //文字中央寄せ
    printer.setSize('M');   //文字サイズ
    printer.println("スコティッシュフォ-ルド");
    printer.println("販売店やんや");
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("214-0030");
    printer.println("住所：神奈川県川崎市タマ区西生田2-8-22 ハイランドハウス403");
    printer.println("電話：080-3689-9405");
    printer.feed(1);
    printer.justify('C');   //文字中央寄せ
    printer.setSize('L');   //文字サイズ
    printer.println("領収書");
    printer.feed(1);
    printer.justify('L');
    printer.setSize('S');
    printer.println("2019年1月26日(土)");
    printer.feed(1);

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコティッシュフォ-ルド");
    printer.justify('R');   //右寄せ
    printer.println("¥40,000");
  }
  if (sei == 1) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥4,708");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥24,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("甲信越・北陸＞長野県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,310");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("まん丸お目目とお顔の可愛い男の子");
    printer.justify('R');   //右寄せ
    printer.println("¥19,300");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2017/09/14（今日で生後480日）");
    printer.justify('R');   //右寄せ
    printer.println("¥10,690");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブラウンタビ-ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥12,070");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("長毛");
    printer.justify('R');   //右寄せ
    printer.println("¥15,370");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ワクチン代");
    printer.justify('R');   //右寄せ
    printer.println("¥4,630");


    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥152,778(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥165,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥12,222円)");
    printer.feed(1);
    printer.printBitmap(neko_1_width, neko_1_height, neko_1_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("子猫ID:1901_00203");
  }

  if (sei == 2) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("セ-ル価格");
    printer.justify('R');   //右寄せ
    printer.println("-¥12,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("半折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ・
    printer.println("¥31,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥17,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関西・近畿＞兵庫県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,469");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("綺麗な色で可愛いお顔");
    printer.justify('R');   //右寄せ
    printer.println("¥1,013");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/09/29(今日で生後100日)");
    printer.justify('R');   //右寄せ
    printer.println("¥17,990");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドマッカレルタビ-");
    printer.justify('R');   //右寄せ
    printer.println("¥9,180");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥126,852円(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥137,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥10,148円)");
    printer.feed(1);
    printer.printBitmap(neko_2_width, neko_2_height, neko_2_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1811_01021");



  }
  if (sei == 3) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥37,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥19,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関西・近畿＞大阪府");
    printer.justify('R');   //右寄せ
    printer.println("¥1,469");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("忍者のような猫ちゃんです。");
    printer.justify('R');   //右寄せ
    printer.println("¥8,200");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/05/11(今日で生後241日)");
    printer.justify('R');   //右寄せ
    printer.println("¥16,280");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ト-ティ-シェル・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥10,007");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("お父さん:ダブルグランドチャンピオン");
    printer.justify('R');   //右寄せ
    printer.println("¥32,000");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥18,5186(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥200,000 円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥14,814円)");
    printer.feed(1);
    printer.printBitmap(neko_3_width, neko_3_height, neko_3_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1806_01335");


  }
  if (sei == 4) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥37,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥22,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関西・近畿＞大阪府");
    printer.justify('R');   //右寄せ
    printer.println("¥1,469");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("とても社交的です。物怖じしません。");
    printer.justify('R');   //右寄せ
    printer.println("¥18,022");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/16(今日で生後44日)");
    printer.justify('R');   //右寄せ
    printer.println("¥31,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブル-クリ-ム");
    printer.justify('R');   //右寄せ
    printer.println("¥32,413");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥203,704(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥220,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥16,296円)");
    printer.feed(1);
    printer.printBitmap(neko_4_width, neko_4_height, neko_4_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1806_01337");

  }
  if (sei == 5) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥1,708");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("足の痛み/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥2,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("四国＞高知県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,577");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("立ち耳男の子");
    printer.justify('R');   //右寄せ
    printer.println("¥2,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/05/03(今日で生後249日)");
    printer.justify('R');   //右寄せ
    printer.println("¥3,427");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブラウンタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥10,070");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥81,482(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥88,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥6,518円)");
    printer.feed(1);
    printer.printBitmap(neko_5_width, neko_5_height, neko_5_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println(" 　子猫ID:1901_00260");

  }
  if (sei == 6) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥27,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥16,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("甲信越・北陸＞長野県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,310");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("ショ-トへア-の可愛い子です。");
    printer.justify('R');   //右寄せ
    printer.println("¥281");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/08/10（今日で生後150日）");
    printer.justify('R');   //右寄せ
    printer.println("¥9,400");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥5,180");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥120,371(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥130,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥9,629円)");
    printer.feed(1);
    printer.printBitmap(neko_6_width, neko_6_height, neko_6_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1809_00660");

  }
  if (sei == 7) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("セール価格");
    printer.justify('R');   //右寄せ
    printer.println("¥6,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥1,708");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥8,400");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("九州・沖縄＞福岡県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,793");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("1月10日までの募集です♪");
    printer.justify('R');   //右寄せ
    printer.println("¥1,254");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/08/07（今日で生後153日）");
    printer.justify('R');   //右寄せ
    printer.println("¥5,320");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドクラシックタビ-");
    printer.justify('R');   //右寄せ
    printer.println("¥2,200");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥74,075(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥80,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥5,925円)");
    printer.feed(1);
    printer.printBitmap(neko_7_width, neko_7_height, neko_7_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1809_00767");

  }
  if (sei == 8) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥14,708");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り・手足の痛み/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥27,740");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞東京都");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("最高に可愛いお顔真ん丸の可愛い男の子です。");
    printer.justify('R');   //右寄せ
    printer.println("¥48,490");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/09/15（今日で生後115日）");
    printer.justify('R');   //右寄せ
    printer.println("¥27,480");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("クリ-ム・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥78,043");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("長毛/毛質");
    printer.justify('R');   //右寄せ
    printer.println("¥35,548");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ワクチン代");
    printer.justify('R');   //右寄せ
    printer.println("¥4,630");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥298,000円(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥321,840円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥23,840円)");
    printer.feed(1);
    printer.printBitmap(neko_8_width, neko_8_height, neko_8_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1810_01539");

  }
  if (sei == 9) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥67,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥38,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("手の痛み/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥33,800");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関西・近畿＞大阪府");
    printer.justify('R');   //右寄せ
    printer.println("¥1,469");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("綺麗な模様入りです。");
    printer.justify('R');   //右寄せ
    printer.println("¥55,386");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/10/10（今日で生後90日））");
    printer.justify('R');   //右寄せ
    printer.println("¥29,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ダイリュ-トキャリコ");
    printer.justify('R');   //右寄せ
    printer.println("¥37,620");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥324,075(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥350,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥25,925円)");
    printer.feed(1);
    printer.printBitmap(neko_9_width, neko_9_height, neko_9_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1810_01699");

  }
  if (sei == 10) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥67,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥27,740");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞東京都");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("お目めクリクリの可愛い男の子です。");
    printer.justify('R');   //右寄せ
    printer.println("¥21,591");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/01(今日で生後68日)");
    printer.justify('R');   //右寄せ
    printer.println("¥27,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブラウンタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥10,070");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("長毛/毛質");
    printer.justify('R');   //右寄せ
    printer.println("¥35,548");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ワクチン代");
    printer.justify('R');   //右寄せ
    printer.println("¥4,630");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥257,040(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥257,040 円（税込）");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥19,040円)");
    printer.feed(1);
    printer.printBitmap(neko_10_width, neko_10_height, neko_10_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1811_01602");

  }
  if (sei == 11) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥27,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("軟骨の痛み");
    printer.justify('R');   //右寄せ
    printer.println("¥10,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞埼玉県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("可愛い系の男の子");
    printer.justify('R');   //右寄せ
    printer.println("¥23,415");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/16(今日で生後53日)");
    printer.justify('R');   //右寄せ
    printer.println("¥27,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥5,180");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥155,556(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥168,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥12,444円)");
    printer.feed(1);
    printer.printBitmap(neko_11_width, neko_11_height, neko_11_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1812_01004");

  }
  if (sei == 12) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥14,708");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("中国＞広島県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,577");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("とっても可愛い男の子です");
    printer.justify('R');   //右寄せ
    printer.println("¥2,904");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/15(今日で生後54日)");
    printer.justify('R');   //右寄せ
    printer.println("¥27,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("カメオタビ-");
    printer.justify('R');   //右寄せ
    printer.println("¥27,100");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥133,889(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥150,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥11,111円)");
    printer.feed(1);
    printer.printBitmap(neko_12_width, neko_12_height, neko_12_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1812_01256");

  }
  if (sei == 13) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥17,710");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り・足の引きずり/骨瘤の疑い");
    printer.justify('R');   //右寄せ
    printer.println("¥37,213");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関西・近畿＞大阪府");
    printer.justify('R');   //右寄せ
    printer.println("¥1,469");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("ハイブリットの配合です。めちゃ可愛いです");
    printer.justify('R');   //右寄せ
    printer.println("¥30,670");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/09(今日で生後60日)");
    printer.justify('R');   //右寄せ
    printer.println("¥24,100");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブラック(高級絨毯モフモフ)");
    printer.justify('R');   //右寄せ
    printer.println("¥60,320");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥231,482(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥250,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥18,518円)");
    printer.feed(1);
    printer.printBitmap(neko_13_width, neko_13_height, neko_13_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1811_01417");

  }
  if (sei == 14) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥67,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り・手足の痛み/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥27,740");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞神奈川県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("甘えん坊くん");
    printer.justify('R');   //右寄せ
    printer.println("¥");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/02(今日で生後67日)");
    printer.justify('R');   //右寄せ
    printer.println("¥22,553");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥5,180");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥183,334(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥198,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥14,666円)");
    printer.feed(1);
    printer.printBitmap(neko_14_width, neko_14_height, neko_14_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1812_00685");


  }
  if (sei == 15) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥17,710");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("手の痛み骨瘤の疑い");
    printer.justify('R');   //右寄せ
    printer.println("¥17,682");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("甲信越・北陸＞長野県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,310");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("犬の様に頭をなぜると尾を振る愛嬌たっぷり");
    printer.justify('R');   //右寄せ
    printer.println("¥2,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/20(今日で生後49日)");
    printer.justify('R');   //右寄せ
    printer.println("¥27,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブル-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥24,024");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ワクチン代");
    printer.justify('R');   //右寄せ
    printer.println("¥4,630");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥155,556(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥168,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥12,444円)");
    printer.feed(1);
    printer.printBitmap(neko_15_width, neko_15_height, neko_15_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println(" 　　子猫ID:1812_01011");


  }
  if (sei == 16) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥60,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥16,920");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("甲信越・北陸＞長野県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,310");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("食欲旺盛元気に沢山食べる遊び大好きな耳折女の子");
    printer.justify('R');   //右寄せ
    printer.println("¥14,313");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/20(今日で生後49日)");
    printer.justify('R');   //右寄せ
    printer.println("¥25,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブル-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥24,024");

    printer.justify('L');   //左寄せ
    printer.println("小　計 8点");

    printer.justify('R');   //右寄せ
    printer.println("¥166,667(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥180,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　¥13,333円)");
    printer.feed(1);
    printer.printBitmap(neko_16_width, neko_16_height, neko_16_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1812_01012");
  }
  if (sei == 17) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥72,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("男の子（オス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥23,920");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("手の痛み/骨瘤の疑い");
    printer.justify('R');   //右寄せ
    printer.println("¥21,339");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("北海道");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("キュートな子");
    printer.justify('R');   //右寄せ
    printer.println("¥30,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/10/24（今日で生後77日）");
    printer.justify('R');   //右寄せ
    printer.println("¥25,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブラウンタビー・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥23,840");

    printer.justify('L');   //左寄せ
    printer.println("小　計  1点");

    printer.justify('R');   //右寄せ
    printer.println("¥259,260(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥280,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　¥20,740円)");
    printer.feed(1);
    printer.printBitmap(neko_17_width, neko_17_height, neko_17_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1811_01428");

  }
  if (sei == 18) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥67,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("スコ座り/骨瘤 ");
    printer.justify('R');   //右寄せ
    printer.println("¥37,213");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞埼玉県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");   //文字左寄せ

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("可愛いブルーの男の子");
    printer.justify('R');   //右寄せ
    printer.println("¥31,812");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/23(今日で生後46日)");
    printer.justify('R');   //右寄せ
    printer.println("¥27,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブル-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥24,024");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥248,149(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥268,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　¥19,851円)");
    printer.feed(1);
    printer.printBitmap(neko_18_width, neko_18_height, neko_18_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1812_01262");

  }
  if (sei == 19) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("立ち耳");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥15,710");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("おとこの子(オス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("手の痛み");
    printer.justify('R');   //右寄せ
    printer.println("¥22,113");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("甲信越・北陸＞長野県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,310");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("ブル-・ホワイトの可愛い遊び好きな男の子。");
    printer.justify('R');   //右寄せ
    printer.println("¥3,021");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/24(今日で生後45日)");
    printer.justify('R');   //右寄せ
    printer.println("¥28,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ブル-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥22,024");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥152,778(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥165,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥12,222円)");
    printer.feed(1);
    printer.printBitmap(neko_19_width, neko_19_height, neko_19_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1901_00204");


  }
  if (sei == 20) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥37,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子（メス）");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("骨瘤の疑い ");
    printer.justify('R');   //右寄せ
    printer.println("¥19,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("関東＞埼玉県");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("キュ-トな可愛い子");
    printer.justify('R');   //右寄せ
    printer.println("¥8,743");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/11/22(今日で生後47日)");
    printer.justify('R');   //右寄せ
    printer.println("¥26,600");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ダイリュ-トキャリコバ-ン");
    printer.justify('R');   //右寄せ
    printer.println("¥24,800");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("ワクチン代");
    printer.justify('R');   //右寄せ
    printer.println("¥4,630");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥183,334(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥198,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　　　¥14,666円)");
    printer.feed(1);
    printer.printBitmap(neko_20_width, neko_20_height, neko_20_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1901_00248");

  }
  if (sei == 21) {
    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("折れ耳・遺伝性軟骨異形成症");//遺伝性軟骨異形成症
    printer.justify('R');   //右寄せ
    printer.println("¥37,500");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("女の子(メス)");
    printer.justify('R');   //右寄せ
    printer.println("¥20,000");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("骨瘤の疑い");
    printer.justify('R');   //右寄せ
    printer.println("¥19,700");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("北海道");
    printer.justify('R');   //右寄せ
    printer.println("¥1,361");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ　
    printer.println("キュ-トな天使ちゃん");
    printer.justify('R');   //右寄せ
    printer.println("¥23,985");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("2018/12/17(今日で生後39日)");
    printer.justify('R');   //右寄せ
    printer.println("¥28,200");

    printer.justify('L');   //文字左寄せ
    printer.setSize('S');   //文字サイズ
    printer.println("レッドタビ-・ホワイト");
    printer.justify('R');   //右寄せ
    printer.println("¥5,180");

    printer.justify('L');   //左寄せ
    printer.println("小　計 1点");

    printer.justify('R');   //右寄せ
    printer.println("¥175,926(税抜)");
    printer.justify('C');   //中央寄せ

    printer.println("...............................");

    printer.setSize('M');   //文字サイズ
    printer.justify('L');   //左寄せ
    printer.doubleWidthOn();
    printer.println("合　計");

    printer.justify('R');  //右寄せ
    printer.println("¥190,000円(税込)");

    printer.doubleWidthOff();
    printer.justify('L');   //左寄せ
    printer.println("(内消費税　  　　¥14,074円)");
    printer.feed(1);
    printer.printBitmap(neko_21_width, neko_21_height, neko_21_data);
    printer.justify('L');  //左寄せ
    printer.println("レジ1-3103");
    printer.justify('R');   //右寄せ
    printer.println("　　子猫ID:1901_00248");

  }

}
