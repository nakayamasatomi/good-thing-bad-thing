import processing.serial.*;
import http.*;

SimpleHTTPServer server;
Serial s ;

//プリンターにデータを送るのに必要な変数
int sei;

void setup() {
  //Arduinoとの接続
  println(Serial.list());
  s = new Serial(this, Serial.list()[2], 9600);

  //サーバーの初期化
  server = new SimpleHTTPServer(this); 
  
  server.serve( "js/jquery-3.3.1.min.js");
  server.serve("js/holder.min.js");
  server.serve("js/bootstrap.min.js");
  server.serve("js/jquery.lazyload.min.js");
  server.serve("css/bootstrap-grid.min.css");
  server.serve("css/bootstrap-reboot.min.css");
  server.serve("database.css");
  server.serve("css/bootstrap.min.css");
  server.serve("neko", "print.html", "neko_printer");
}


void neko_printer(String uri, HashMap<String, String> parameterMap) {
  // webページのURLから情報を取得
  println("uri:", uri, "parameters:");
  println(parameterMap);


  // http://localhost:8000/neko?se=0&mi=0&im=0 こういうURLから
  // 必要な情報を取り出す

  sei = int(parameterMap.getOrDefault("se", "0")); // 性別

  //デバッグ表示用
  println(sei);

  //Arduinoへシリアルデータ送信
  s.write("se="+sei);
  s.write("\n");
  s.write("pr=1");//プリントするフラグ
  s.write("\n");

  println("send");
}

void draw() {
}
