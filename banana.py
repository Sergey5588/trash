import pyautogui as pg
import os
import time
import keyboard as k
import winsound as ws
import win32gui as w





time.sleep(150)

os.system(r'"E:\SteamLibrary\steamapps\common\Banana\Banana.exe"')
time.sleep(70)

os.system('taskkill /F /IM "Banana.exe"')
while True:
    time.sleep(10800)
    time.sleep(30)

    os.system(r'"E:\SteamLibrary\steamapps\common\Banana\Banana.exe"')
    time.sleep(10)
    
    pg.click(943,466)
    time.sleep(180)
    os.system('taskkill /F /IM "Banana.exe"')
