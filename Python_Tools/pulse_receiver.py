import serial
import time
import csv

# === CONFIGURATION ===
PORT = "COM4"  # Change to your Arduino/Bluetooth COM port
BAUD_RATE = 115200
LOG_TO_CSV = True

csv_file = "bpm_log.csv"
ser = serial.Serial(PORT, BAUD_RATE, timeout=1)

print(f"Connecting to {PORT} at {BAUD_RATE} baud...")
time.sleep(2)
print("Connected.\nListening for BPM data...")

if LOG_TO_CSV:
    csvfile = open(csv_file, 'w', newline='')
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(["Timestamp", "BPM"])

try:
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line.startswith("BPM:"):
            bpm = line.split(":")[1].strip()
            timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
            print(f"[{timestamp}] BPM: {bpm}")
            if LOG_TO_CSV:
                csvwriter.writerow([timestamp, bpm])
except KeyboardInterrupt:
    print("\nStopped by user.")
finally:
    if LOG_TO_CSV:
        csvfile.close()
    ser.close()
