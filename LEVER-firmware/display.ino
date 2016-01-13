void updateDisplay(long pos) {
  /*
  display.clearDisplay();
  for (int i = 0; i < display.width(); i++) {
    int barOffset = int(map(phaseOffset, maxFreq, minFreq, 0, display.width() / 2));
    if (i % barOffset <= barOffset / 2) {
      // fill in the column if it's not
      display.drawLine(i, 0, i, display.height() - 28, WHITE);
    }
<<<<<<< HEAD
    */
  Serial.print("encMode ="); Serial.println(modeLabels[encMode]);
  Serial.print("waveType ="); Serial.println(waveLabels[waveType]);
  int freq = int(map(phaseOffset, minFreq, maxFreq, 37.5, 1200));
  Serial.print("freq ="); Serial.println(freq);
  Serial.print("amp =");  Serial.println(DACamplitude / maxAmpl);
  Serial.print("duty =");  Serial.println(int(dutyCycle * 100));
  Serial.print("pos =");  Serial.println(pos);
  Serial.println("------------------------------------");

  /*
=======
  }

>>>>>>> origin/master
  display.setCursor(2, display.height() - 24);
  display.print(modeLabels[encMode]);
  
  display.setCursor(42, display.height() - 24);
  display.print(waveLabels[waveType]);
  
  display.setCursor(82, display.height() - 24);
  int freq = int(map(phaseOffset, minFreq, maxFreq, 37.5, 1200));
  display.print(int(freq));
  
  display.setCursor(2, display.height() - 12);
  display.print(DACamplitude / maxAmpl);
  
  display.setCursor(42, display.height() - 12);
  display.print(int(dutyCycle * 100));
  display.print("%");
  
  display.setCursor(82, display.height() - 12);
  display.print(pos);
  display.display();
  */
}
<<<<<<< HEAD

=======
>>>>>>> origin/master
