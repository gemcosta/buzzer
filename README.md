# buzzer
A simple solution to a common inconvenience. This is a few simple lines of code that uses the "TwiML" markup language, designed to run with a Twilio account and number. Read on if you're interested.

### The Problem
Whether you run an Airbnb, or tend to have lots of guests, apartment owners have long struggled with a simple problem. Those pesky callboxes. You have to hear your phone ring, answer it, and dial `9` a bunch of times to make sure the call box received the command to unlock the door.

### The Solution
1. Purchase a local number from [Twilio](https://www.twilio.com/)
2. I use a combination of [Twilio's programmable voice](https://www.twilio.com/voice) and [TwiML Bins](https://www.twilio.com/docs/voice/twiml)
3. Write and upload the code to Twilio's servers so that it runs every time it receives a call
4. Change the callbox's destination number to the new Twilio number. 

1/9/2020: I have updated my solution in order to address a new problem. I was getting phone calls from robo-callers, which was not only using up my funds to execute the code on Twilio, it was texting my phone alerting me someone was buzzing into the door (when in reality no one was there).

So I elected to create a "virtual blacklist" by taking advantage of Twilio's new "Functions" feature. See blacklist.cpp
Then, I configured my number to execute the function (called "blacklist") if it receives a call. This function also executes the above TwiML code after it determines the call is not an unwanted number. Otherwise, it will reject the call.

1/10/2020: It quickly became apparent that the virtual blacklist was actually not going to work because the functionality was limited to checking against an array of numbers that were already known. So I would have to wait until I already got an unwanted call, and add them to this "blacklist". But this defeats the purpose, as I want my function to ONLY accept a single number. After some time, I figured out that there is such a version of this function called a "whitelist", where the code will check that the incoming caller matches a known number instead. See whitelist.cpp for the code!

### Distribution
Feel free to use this code yourself. Use at your own discretion.
