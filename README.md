# DataHarvester

## Requirements
* Digispark ATTINY85 USB Development board (around 3-5 USD) [e.g. from Aliexpress](https://www.aliexpress.com/item/2040316211.html)

## Demo

[![](https://markdown-videos-api.jorgenkh.no/youtube/sxPgF-FfOt0)](https://youtu.be/sxPgF-FfOt0})

## Setup

### Server

#### Installation
1. Install Python 3.x from the [official website](https://www.python.org/downloads/).
2. Clone the repository:
    ```sh
    git clone https://github.com/q1000q/DataHarvester.git
    ```
3. Navigate to the server directory:
    ```sh
    cd DataHarvester/server
    ```
4. Install the required Python packages:
    ```sh
    pip install -r requirements.txt
    ```

#### Configuration (optional)
1. Create and edit .env file in server directory (or use system env varibles)
2. If you want to change the directory where the compressed filles will be dumped add `UPLOAD_FOLDER` variable with relative path from `server.py`
3. If you want to get notifications when you get a zip file, set the `NTFY_ADDRESS` to use ntfy.sh notification services

#### Running the Server
1. Start the Flask server:
    ```sh
    python server.py
    ```
2. The server will be running at `http://0.0.0.0:5000/`.


### BadUSB

#### Installation
1. Install [PlatformIO IDE](https://platformio.org/install/ide?install=vscode) for Visual Studio Code.
2. Clone the repository:
    ```sh
    git clone https://github.com/q1000q/DataHarvester.git
    ```
3. Open the project folder in Visual Studio Code.

#### Configuration
1. Open the `platformio.ini` file and ensure it contains the following configuration:
    ```ini
    [env:digispark-tiny]
    platform = atmelavr
    board = digispark-tiny
    framework = arduino
    ```
2. Edit server address in `src/main.cpp` file

#### Uploading the Code
1. In Visual Studio Code, open the PlatformIO extension.
2. Click on the "Upload" button to compile and upload the code to the Digispark ATTINY85 board.
3. Connect Digispark ATTINY85 board to the computer.
4. Wait until the upload process is complete. **(Beware: Script can run right after the upload)**