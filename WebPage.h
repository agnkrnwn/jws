const char webpage[] PROGMEM = 
R"=====(

<!DOCTYPE html>
<html>
<meta name="viewport" content="width=device-width, initial-scale=1">
<head>
<title>JWS </title>
<style>
    *{box-sizing:border-box}body{font-family:Arial,Helvetica,sans-serif}.navbar{width:100%;background-color:#555;overflow:hidden;position:fixed}.navbar a{float:left;padding:12px;color:#fff;text-decoration:none;font-size:17px;width:20%;text-align:center}.navbar a:hover{background-color:#000}.navbar a.active{background-color:#04AA6D}@media screen and (max-width:500px){.navbar a{float:none;display:block;width:100%;text-align:left}}.button{background-color:green;border:none;color:#fff;padding:10px;text-align:center;text-decoration:none;display:inline-block;font-size:16px;margin:4px 2px;cursor:pointer}.button1{border-radius:9px;width:35%}.button2{width:35%;border-radius:9px}.button21{background-color:#fff;width:35%;border-radius:9px;border:none;color:#fff;padding:10px;text-align:center;text-decoration:none;display:inline-block;font-size:16px;margin:4px 2px}.button20{background-color:#f2f2f2;width:35%;border-radius:9px;color:#f2f2f2}.button3{width:100%;border-radius:9px;background-color:#555}input[type=text],select{width:100%;padding:12px 20px;margin:8px 0;display:inline-block;border:1px solid #ccc;border-radius:4px;box-sizing:border-box}input[type=submit]{width:100%;background-color:#4caf50;color:#fff;padding:14px 20px;margin:8px 0;border:none;border-radius:4px;cursor:pointer}input[type=time]{width:100%;background-color:#fcfbfb;color:#000;padding:14px 20px;margin:8px 0;border:none;border-radius:4px;cursor:pointer}input[type=date]{width:100%;background-color:#fcfbfb;color:#000;padding:14px 20px;margin:8px 0;border:none;border-radius:4px;cursor:pointer}input[type=submit]:hover{background-color:#45a049}div{flex:1;display:flex;align-items:center;border-radius:5px;background-color:#f2f2f2;padding:20px}textarea{width:100%;height:150px;padding:12px 20px;box-sizing:border-box;border:2px solid #ccc;border-radius:4px;background-color:#f8f8f8;font-size:16px;resize:none}.slidecontainer{width:100%}.slider{-webkit-appearance:none;width:100%;height:25px;background:#d3d3d3;outline:none;opacity:.7;-webkit-transition:.2s;transition:opacity .2s}.slider:hover{opacity:1}.slider::-webkit-slider-thumb{-webkit-appearance:none;appearance:none;width:25px;height:25px;background:#04AA6D;cursor:pointer}.slider::-moz-range-thumb{width:25px;height:25px;background:#04AA6D;cursor:pointer}h1,h2,h3,p{text-align:center;color:#000}table{border-collapse:collapse;width:100%}th,td{padding:8px;text-align:left;border-bottom:1px solid #ddd}.info{background-color:#eee;border-radius:25px;padding-top:17px;margin:5px;text-align:center}p.info{padding:7px}span{text-align:center}
</style>
</head>
<body onload="updateData()">
<div class="navbar">
  <a class="active" href="#">Home</a> 
  <a href="#mediax">Media</a> 
  <a href="#infox">Info</a>
  <a href="#jwsx">JWS</a>
  <a href="#wifix">Wifi</a>
  
</div>
<div id="mediax">
    <div class="button button20">
      <p>yomama</p>
    </div>
</div>
<div >
    <div class="info">
        <span id="day"></span>/<span id="month"></span>/<span id="year"></span><span> </span>
    </div>
    <div class="info">
        <span id="hour"></span>:<span id="minute"></span>:<span id="second"></span><span> </span>
    </div>
    <div class="info">
        <span id="temp"></span><span>C</span>
    </div>
</div>

<h2> Media controller</h2>

<div>
    <select id="playlist" onchange="sendPlaylist()">
      <option value="p1">Al Quran Dibacakan Oleh...</option>
      <option value="p2">Al Quran - Saad Alghamdi</option>
      <option value="p3">Juz Amma - Saad Alghamdi</option>
      <option value="p4">Al Quran - Mishary Rasyid</option>
      <option value="p5">Juz Amma - Mishary Rasyid</option>
      <option value="p6">Al Quran - As Sudais</option>
      <option value="p7">Juz Amma - As Sudais</option>
      <option value="p8">Al Quran - Al Budair</option>
      <option value="p9">Juz Amma - Al Budair</option>
      <option value="pl1">Al Quran - Al Muaiqly</option>
      <option value="pl2">Juz Amma - Al Muaiqly</option>
      <option value="pl3">Al Quran - Al Hudhaifi</option>
      <option value="pl4">Juz Amma - Al Hudhaifi</option>
      <option value="pl5">Lain-lain</option>
    </select>
</div>
<div>
    <select id="equalizer" onchange="sendEqualizer()">
      <option value="e0">Pilih Equalizer...</option>
      <option value="e1">Normal</option>
      <option value="e2">Pop</option>
      <option value="e3">Rock</option>
      <option value="e4">Jazz</option>
      <option value="e5">Classic</option>
      <option value="e6">Bass</option>
    </select>
</div>
<div id="con">
    <a href="#mediax" class="play button button1" id="play" onclick="sendPlay()">&#x25B6; Play</a>
    <a href="#mediax" class="play button button1" id="pause" onclick="sendPause()">&#x23F8; Pause</a>
    <a href="#mediax" class="play button button1" id="stop" onclick="sendStop()">&#x23F9; Stop</a>
</div>
<div>
    <a href="#mediax" class="play button button1" id="prev" onclick="sendPrev()">&#x23F4; Prev</a>
    <a href="#mediax" class="play button button1" id="random" onclick="sendRandom()">&#x219D; Random</a>
    <a href="#mediax" class="play button button1" id="next" onclick="sendNext()">&#x23F5; Next</a>
</div>
<div>
    <div class="slidecontainer">
        &#x1F50A; <input class="slider" type="range" min="0" max="30" value="15" id="volume" oninput="sendVolume()" />
    </div>
</div>
<h2> Mode controller </h2>
<div>
    <a href="#con" class="button button2" id="modejam" onclick="sendModeJam()">JWS</a>
    <a href="#con" class="button button2" id="modemp3" onclick="sendModeMP3()">Murottal</a> 
    <a href="#con" class="button button2" id="modetesled" onclick="sendTesLED()">Tes LED</a> 
</div>
<div >
    <div class="slidecontainer">
        <input class="slider" type="range" min="15" max="254" value="20" id="kecerahan" oninput="sendKecerahan()" />&#x1F506
    </div> 
</div>
<div>
    <div id="infox">
        <select id="panel" onchange="sendKecerahan()">
          <option value="1">1 Panel</option>
          <option value="2">2 Panel</option>
          <option value="3">3 Panel</option>
          <option value="4">4 Panel</option>
        </select>
      </div>
</div>
<h2 >Informasi controller</h2>
<div>
 <textarea id="info1" placeholder="Info1" onchange="sendNama()"></textarea>
</div>
<div>
 <textarea id="info2" placeholder="Info2" onchange="sendNama()"></textarea>
</div>
<div id="jwsx">
 <textarea id="nama" placeholder="Nama Masjid" onchange="sendNama()"></textarea>
</div>
<h2 >Jadwal Sholat</h2>
<div>
    <table>
        <tr>
          <td><p id="jtanbih" class="info"></p></td>
          <td><p id="jsubuh" class="info"></p></td>
          <td><p id="jdzuhur" class="info"></p></td>
        </tr>
        <tr>
          <td><p id="jashar" class="info"></p></td>
          <td><p id="jmaghrib" class="info"></p></td>
          <td><p id="jisya" class="info"></p></td>
        </tr>
      </table>
</div>
<h2>Iqomah</h2>
<div>
    <table >
      <tr>
        <td>
          <label for="iqmhs">Subuh</label><br>
          <input type="text" id="iqmhs" placeholder="12" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmhd">Dzuhur</label><br>
          <input type="text" id="iqmhd" placeholder="8" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmha">Ashar</label><br>
          <input type="text" id="iqmha" placeholder="6" maxlength="2" size="2" onchange="setJws()"/>
        </td>
      </tr>
      <tr>
        <td>
          <label for="iqmhm">Maghrib</label><br>
          <input type="text" id="iqmhm" placeholder="5" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmhi">Isya</label><br>
          <input type="text" id="iqmhi" placeholder="5" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="durasiadzan">Adzan</label><br>
          <input type="text" id="durasiadzan" placeholder="2" maxlength="2" size="2" onchange="setJws()"/>
        </td>
      </tr>
    </table>    
</div>
<h2>waktu dan Lokasi</h2>
<div>
    <table >
        <tr>
          <td>
            <form >
              <h4>Tanggal</h4>
              <input type="date" name="date" id="tanggal" onchange="sendTanggal()">
            </form>  
          </td>        
        </tr>
        <tr>
          <td>
            <form >  
              <h4>Jam</h4>
              <input type="time" name="time" id="jam" onchange="sendJam()">
            </form>
          </td>
        </tr>
      </table>      
</div>
<div>
    <table>
        <tr>
          <td>
            <label for="latitude">Latitude</label><br>
            <input type="text" id="latitude" placeholder="-6.165" size="9" onchange="setJws()"/>
          </td>
          <td>
            <label for="longitude">Longitude</label><br>
            <input type="text" id="longitude" placeholder="106.608" size="9" onchange="setJws()"/>
          </td>    
        </tr>
        <tr id="wifix">
          <td>
            <label for="zonawaktu">Zona Waktu</label><br>
            <input type="text" id="zonawaktu" placeholder="7" size="2" onchange="setJws()"/>
          </td>
          <td>
            <label for="ihti">Ihtiyati</label><br>
            <input type="text" id="ihti" placeholder="2" maxlength="2" size="2" onchange="setJws()"/>
          </td>
        </tr>
      </table>
</div>
<h2>Wifi settings</h2>
<form>
    <h3>Sambung ke Wifi</h3>
    <div>
      <input type="text" id="wifissid" placeholder="Wifi SSID" onchange="setWifi()"/>
    </div>
    <div>
      <input type="text" type="password" id="wifipassword" placeholder="Wifi Password" onchange="setWifi()"/>
    </div>
    
    <h3>Wifi JWS</h3>
    <div>
      <input type="text" id="ssid" placeholder="nama wifinya" onchange="setWifi()"/>
    </div>
    <div>
      <input type="text" type="password" id="password" placeholder=" passwordnya" onchange="setWifi()"/>
    </div>
    <div>
      <button class="button button3" onClick="resetNodeMCU()"> Terapkan dan Restart </button>
    </div>
</form>
</body>
<script>

    var xmlHttp=createXmlHttpObject();
    
    function createXmlHttpObject(){
     if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
     }else{
        xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');// code for IE6, IE5
     }
     return xmlHttp;
    }
    
    function updateData() {
      process();
      processreal();
    }
    
    function process(){
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
       xmlHttp.open('PUT','xml',true);
       xmlHttp.onreadystatechange=handleServerResponse;
       xmlHttp.send(null);
     }
    
     //setTimeout('process()',1000);
    
    }
    
    function processreal(){
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
       xmlHttp.open('PUT','realxml',true);
       xmlHttp.onreadystatechange=handleRealServerResponse;
       xmlHttp.send(null);
     }
    
     setTimeout('processreal()',1000);
    
    }
    
    function handleServerResponse(){
     if(xmlHttp.readyState==4 && xmlHttp.status==200){
       xmlResponse=xmlHttp.responseXML;
    
       xmldoc = xmlResponse.getElementsByTagName('rNama');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('nama').value=message;
       
       xmldoc = xmlResponse.getElementsByTagName('rInfo1');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('info1').value=message;
       
       xmldoc = xmlResponse.getElementsByTagName('rInfo2');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('info2').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhs');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhs').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhd');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhd').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmha');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmha').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhm');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhm').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIqmhi');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('iqmhi').value=message;
    
        xmldoc = xmlResponse.getElementsByTagName('rDurasiAdzan');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('durasiadzan').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIhti');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('ihti').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rLatitude');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('latitude').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rLongitude');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('longitude').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rZonaWaktu');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('zonawaktu').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rSsid');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('ssid').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rPassword');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('password').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rWifissid');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('wifissid').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rTanbih');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jtanbih').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rSubuh');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jsubuh').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rDzuhur');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jdzuhur').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rAshar');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jashar').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rMaghrib');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jmaghrib').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rIsya');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('jisya').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rPanel');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('panel').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rWifipassword');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('wifipassword').value=message;
    
     }
    }
    
    
    function handleRealServerResponse(){
     if(xmlHttp.readyState==4 && xmlHttp.status==200){
       xmlResponse=xmlHttp.responseXML;
    
       xmldoc = xmlResponse.getElementsByTagName('rYear');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('year').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rMonth');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('month').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rDay');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('day').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rHour');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('hour').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rMinute');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('minute').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rSecond');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('second').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rTemp');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('temp').innerHTML=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rVolume');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('volume').value=message;
    
       xmldoc = xmlResponse.getElementsByTagName('rKecerahan');
       message = xmldoc[0].firstChild.nodeValue;
       document.getElementById('kecerahan').value=message;
    
     }
    }
    
    
    InitWebSocket()
    
    function InitWebSocket() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      Socket.onmessage = function(event) {
        
      }
    
      Socket.onclose = function(event) {
        location.reload();
      }
    }
    
    function sendVolume() {    
      var volume = document.getElementById("volume").value;
      var datadf = {volume:volume};
      Socket.send("#" + JSON.stringify(datadf));
    }
    
    function sendPlay() {
      Socket.send("dplay");
    }
    function sendPause() {
      Socket.send("dpause");
    }
    function sendStop() {
      Socket.send("dstop");
    }  
    function sendPrev() {
      Socket.send("dprev");
    }
    function sendNext() {
      Socket.send("dnext");
    }
    function sendRandom() {
      Socket.send("drandom");
    }
    function sendModeMP3() {
      Socket.send("dmodemp3");
    }
    function sendModeJam() {
      Socket.send("dmodejam");
    }
    function sendPlaylist() {
      var option = document.getElementById("playlist").value;
      Socket.send(option);
    }
    function sendEqualizer() {
      var option = document.getElementById("equalizer").value;
      Socket.send(option);
    }
    
    function sendTanggal() {
      Socket.send("t" + document.getElementById("tanggal").value);
    }
    function sendJam() {
      Socket.send("j" + document.getElementById("jam").value);
    }
    
    function sendNama() {
      var nama = document.getElementById("nama").value;
      var info1 = document.getElementById("info1").value;
      var info2 = document.getElementById("info2").value;
      var datainfo = {nama:nama, info1:info1, info2:info2};
      Socket.send("i" + JSON.stringify(datainfo));
    }
    
    function sendKecerahan() {
      var kecerahan = document.getElementById("kecerahan").value;
      var panel = document.getElementById("panel").value;
      var datadisp = {kecerahan:kecerahan, panel:panel};
      
      Socket.send("c" + JSON.stringify(datadisp));
    }
    
    
    function setJws() {
      
      var iqmhs = document.getElementById("iqmhs").value;
      var iqmhd = document.getElementById("iqmhd").value;
      var iqmha = document.getElementById("iqmha").value;
      var iqmhm = document.getElementById("iqmhm").value;
      var iqmhi = document.getElementById("iqmhi").value;
      var durasiadzan = document.getElementById("durasiadzan").value;
      var ihti = document.getElementById("ihti").value;
      var latitude = document.getElementById("latitude").value;
      var longitude = document.getElementById("longitude").value;
      var zonawaktu = document.getElementById("zonawaktu").value;
      var datajws = {iqmhs:iqmhs, iqmhd:iqmhd, iqmha:iqmha, iqmhm:iqmhm, iqmhi:iqmhi, durasiadzan:durasiadzan, ihti:ihti, latitude:latitude, longitude:longitude, zonawaktu:zonawaktu};
    
      Socket.send("s" + JSON.stringify(datajws));    
      
    }
    
    function setWifi() {
    
      var wifissid = document.getElementById("wifissid").value;
      var wifipassword = document.getElementById("wifipassword").value;
      var ssid = document.getElementById("ssid").value;
      var password = document.getElementById("password").value;
      var datawifi = {wifissid:wifissid, wifipassword:wifipassword, ssid:ssid, password:password};
    
      Socket.send("w" + JSON.stringify(datawifi));
      
    }
    
    function resetNodeMCU() {
    
      Socket.send("z");
      
    }
    
    function sendTesLED() {
      
      Socket.send("dtesled");
      
    }
    
    
    
    var foldermp3 = document.getElementById("foldermp3");
    var trackmp3 = document.getElementById("trackmp3");
    
    //Create array of options to be added
    var array = ["Saad Alghamdi","Mishary Rasyid","As Sudais","Al Budair","Al Muaiqly","Al Hudhaifi","Lain-lain"];
    
    //Create and append select list
    var slmp3 = document.createElement("select");
    slmp3.setAttribute("id", "slmp3");
    foldermp3.appendChild(slmp3);
    
    var trmp3 = document.createElement("select");
    trmp3.setAttribute("id", "trmp3");
    trackmp3.appendChild(trmp3);
    
    //Create and append the options
    for (var i = 0; i < array.length; i++) {
        var option = document.createElement("option");
        option.setAttribute("value", array[i]);
        option.text = array[i];
        slmp3.appendChild(option);
    }
    
    for (var i = 0; i < 115; i++) {
        var option = document.createElement("option");
        option.setAttribute("value", i);
        option.text = i;
        trmp3.appendChild(option);
    }
    
    function sendPlayFolderTrack() {
      var foldermp3 = document.getElementById("foldermp3").value;
      var trackmp3 = document.getElementById("trackmp3").value;
      Socket.send(foldermp3 + trackmp3);
    }
    
    
</script>
</html> 

)=====";
