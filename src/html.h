#include <ESPAsyncWebServer.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    div{
      font-size: 1.5rem;
      vertical-align:middle;
      padding: 15px;
      background-color: lightblue;
      border-style: solid;
      border-color: white;
      
    }
  </style>
</head>
<body>
  <h2>ESP32  Server</h2>
    <div >Temperature
    <span id="temperature">%TEMPERATURE%</span>
    </div> 
    
    <div >Humidity
    <span id="humidity" >%HUMIDITY%</span>
    </div> 
    
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 100 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 100 ) ;
</script>
</html>)rawliteral";