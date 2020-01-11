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

### How to use this code yourself

Before you get started, you will need to have a programmable callbox. Only callboxes that make outbound calls to numbers will work (in other words, callboxes that have a hardline to an intercom are not compatible).
You will also need a credit card to purchase a Twilio number and add a small amount of funds to your balance. I spent only $1 for my phone number and put $20 on my balance and it has lasted me over a year now without more funds being added.

1. Sign up for Twilio (free): https://www.twilio.com/try-twilio
2. Purchase a phone number (normally $1 USD)
3. From the Console (Twilio's dashboard) navigate to your [TwiML Bins](https://www.twilio.com/console/twiml-bins)
4. Copy my code from `buzzer.bin` into your new TwiML Bin. Call it whatever you want, but be sure to edit the code with the correct phone numbers for you.
5. If you're not worried about robocallers, all you have left to do is go to [Active Numbers](https://www.twilio.com/console/phone-numbers/incoming), click your number, and configure your "Voice & Fax" settings as follows:

![twiml only settings](https://github.com/gemcosta/buzzer/blob/master/twiml_settings.png)

6. If you want to prevent any unwanted callers like myself, navigate to your [Functions](https://www.twilio.com/console/functions/manage), and create a new function from scratch (do not use a template).
7. Copy/paste the code from `whitelist.cpp`, and be sure to replace the phone number(s) in `event.whitelist` to be the only number(s) you want to allow. I personally have the callbox number and my personal number. Be sure to also replace your `twiml.redirect` with your TwiML PATH URL.
8. Name the function "whitelist", and give it the same PATH name so it is easy to recognize.
9. Go back to your [Active Numbers](https://www.twilio.com/console/phone-numbers/incoming), and configure your "Voice & Fax" settings as follows:

![whitelist settings](https://github.com/gemcosta/buzzer/blob/master/whitelist_settings.png)

10. Test your whitelist by calling your Twilio number and see if it executes the TwiML code. If your call was rejected, double check that the number you're calling from is included in the whitelist. 

That's it! 


### Distribution
Feel free to use this code yourself. Use at your own discretion.
