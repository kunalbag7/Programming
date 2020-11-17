import sounddevice
from scipy.io.wavfile import write

fs=44100
sec=60
print("Recording.........")
record_voice=sounddevice.rec(int(sec * fs), samplerate=fs,channels=2)
sounddevice.wait()
write("output.wav",fs, record_voice)