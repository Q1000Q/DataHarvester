from flask import Flask, request, send_from_directory, jsonify
import os
from datetime import datetime
import requests
from dotenv import load_dotenv

load_dotenv()
NTFY_ADDRESS = os.getenv('NTFY_ADDRESS') or ""
UPLOAD_FOLDER = os.getenv('UPLOAD_FOLDER') or "uploads"

app = Flask(__name__)
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

@app.route('/')
def index():
    return "File Server is Running"

@app.route('/upload', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return jsonify({"error": "No file part"}), 400
    file = request.files['file']
    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400
    
    current_time = datetime.now().strftime("%Y%m%d_%H%M%S")

    if NTFY_ADDRESS != "":
        message = f"File {file.filename} uploaded successfully at {current_time}".encode(encoding='utf-8')
        requests.post(NTFY_ADDRESS, data=message)

    file_path = os.path.join(UPLOAD_FOLDER, f"{current_time}_{file.filename}")
    file.save(file_path)
    return jsonify({"message": "File uploaded successfully"}), 200

@app.route('/list', methods=['GET'])
def list_files():
    files = os.listdir(UPLOAD_FOLDER)
    return jsonify(files), 200

@app.route('/download/<filename>', methods=['GET'])
def download_file(filename):
    return send_from_directory(UPLOAD_FOLDER, filename, as_attachment=True)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)