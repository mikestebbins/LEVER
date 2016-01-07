Mike's notes (2016-01-04)
1. schematic and silk screen say 2.2 uF capacitor for C1, but link to part in BOM is for a 2200 pF, or 0.0022 uF
2. 220k resistor spec'd in BOM is WAY too small for pad on board, had to use jumper wire that looks about 50% successful.
3. Arduino code is all for encoder (except for board testing code), but Eagle Board/Schematic files don't seem to have all the necessary hook-ups for encoder to Teensy.
4. May have screwed up and forgot to cut Teensy's trace for battery operation before soldering to board.


# LEVER
####Experiments in electrovibration interaction strategies, inspired by Disney Research papers "Tesla Touch" and "Revel"

Here are the papers I am trying to implement here:
http://www.ivanpoupyrev.com/e-library/2010/teslatouchUIST2010.pdf

http://www.disneyresearch.com/wp-content/uploads/REVEL.pdf

###Summary
Basically, the papers describe a way to augment surfaces with _dynamically changeable tactile properties_ - a surface can change from sticky to slippery basically at will.

###Status
This work is incomplete and ongoing - for one thing, while the circuit decribed here works, I have yet to implement current-sensing feedback as described in the papers. I'm eager to accomplish this because it allows normalization of sensation across people, skin moistures, and time.

###Why I am interested
I'm interested in experimenting with this technology as applied to various notification strategies, particularly on mobile and wearable devices.
I would like to develop interactions in which a person queries a "stack" of stuff waiting for them, rather than being interrupted by a push notification.
The appeal of this technology in this application is that it's totally silent and able to be done without interrupting the person's conversation by stealing focus.
If this technology is implemented on the back of a mobile device, for example, simply rubbing a finger along the back of the phone is all that is needed to see the magnitude of my "stack."
Of course, "stack" can be many things: number of unread emails, number of to-do items, number of places of interest very near me, and so on.

###This repository
The purpose of this repo is to make my work shareable - I had a fair amount of trouble trying to go from the research paper to a safe, working circuit, and I'm hoping to save others some work.

The circuitboard isn't what I would put onto a phone - it is instead a platform for trying out different waveforms, intensities, and so on.

The intent is that you will use the board to figure out the correct implementation details and then generate your own board with a more appropriate layout.

###Requirements
You should follow the BOM pretty precisely unless you know what you are doing. The circuit is designed to work with a 9v battery and I will be trying to allow smaller/more power supplies to work with it. The microcontroller is a Teensy 3.1

###Thanks
I'm so grateful to Disney Research, Ivan Poupyrev, Olivier Bau, and others who worked on the papers for making their work available - I never would have known aobut this cool phoneomenon without their shared work! Thanks as well to nytlabs for supporting my explorations and letting me share in kind.
