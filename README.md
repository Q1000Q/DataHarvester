# DataHarvester

## Requirements
* Digispark ATTINY85 USB Development board (around 3-5 USD) [e.g. from Aliexpress](https://www.aliexpress.com/item/2040316211.html)

## Demo



## Setup

### Server

#### Installation
1. Install Python 3.x from the [official website](https://www.python.org/downloads/).
2. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/DataHarvester.git
    ```
3. Navigate to the server directory:
    ```sh
    cd DataHarvester/server
    ```
4. Install the required Python packages:
    ```sh
    pip install -r requirements.txt
    ```

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
    git clone https://github.com/yourusername/DataHarvester.git
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