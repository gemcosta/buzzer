# buzzer
A simple solution to a common inconvenience. This is a few simple lines of code that uses the "TwiML" markup language, designed to run with a Twilio account and number. Read on if you're interested.

### The Problem
Whether you run an Airbnb, or tend to have lots of guests, apartment owners have long struggled with a simple problem. Those pesky callboxes. You have to hear your phone ring, answer it, and dial `9` a bunch of times to make sure the call box received the command to unlock the door.

### The Solution
1. Purchase a local number from [Twilio](https://www.twilio.com/)
2. I use a combination of [Twilio's programmable voice](https://www.twilio.com/voice) and [TwiML Bins](https://www.twilio.com/docs/voice/twiml)
3. Write and upload the code to Twilio's servers so that it runs every time it receives a call
4. Change the callbox's destination number to the new Twilio number. 

### Distribution
Feel free to use this code yourself. Use at your own discretion.
