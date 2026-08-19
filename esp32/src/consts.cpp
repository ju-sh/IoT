#include<Arduino.h>
#include "consts.h"

const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>Switch</title>

<style>
html, body {
  height: 100%;
  margin: 0;
}

body {
  font-family: sans-serif;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  text-align: center;
}

h1 {
  font-size: 6vw;
  margin-bottom: 8vh;
}

.buttons {
  display: flex;
  justify-content: center;
  gap: 8vw;
}

.circle-button {
  width: 30vw;
  height: 30vw;
  border-radius: 10%;
  border: none;
  background-color: #2196F3;
  color: white;
  font-size: 8vw;
  font-weight: bold;
}

.circle-button:active {
  background-color: #1565C0;
  transform: scale(0.95);
}

#message {
  margin-top: 8vh;
  font-size: 5vw;
}
</style>

</head>

<body>

<h1>ESP32 Control Panel</h1>

<div class="buttons">
  <button class="circle-button" onclick="sendCommand('fan')">
    Fan
  </button>

  <button class="circle-button" onclick="sendCommand('light')">
    Light
  </button>
</div>

<p id="message">Ready</p>

<script>
function sendCommand(name) {
  fetch("/buttons?name=" + name)
    .then(response => response.text())
    .then(data => {
      document.getElementById("message").textContent = data;
    })
    .catch(() => {
      document.getElementById("message").textContent = "Error";
    });
}
</script>

</body>
</html>
)rawliteral";

char buff[30];


/*
<html>
<head>
<title>ESP32 Control</title>
</head>

<body>
<h1>ESP32 Control Panel</h1>

<button onclick="sendCommand('btn-fan')">Button 1</button>
<button onclick="sendCommand('btn-light')">Button 2</button>

<p id="message">Ready</p>

<script>
function sendCommand(cmd) {
  fetch(cmd)
    .then(response => response.text())
    .then(data => {
      document.getElementById("message").innerHTML = data;
    });
}
</script>

</body>
</html>
*/
