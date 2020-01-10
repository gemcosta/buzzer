exports.handler = function(context, event, callback) {
  // List all ALLOWED phone numbers in quotes and E.164 formatting, separated by a comma
  let whitelist = event.whitelist || [ "+12066324139", "+15614528021" ];  
  let twiml = new Twilio.twiml.VoiceResponse();
  let blocked = true;
  if (whitelist.length > 0) {
    if (whitelist.indexOf(event.From) !== -1) {
      blocked = false;
    }
  }
  if (blocked) {
    twiml.reject();
  }
  else {
  // if the caller's number is not blocked, redirect to your existing webhook
  twiml.redirect("https://handler.twilio.com/twiml/EH1ce25b6b00b133847306b84f644e307f");
  }
  callback(null, twiml);
};
