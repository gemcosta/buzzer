exports.handler = function(context, event, callback) {
  // List all blocked phone numbers in quotes and E.164 formatting, separated by a comma
  let blacklist = event.blacklist || ["+15551234567"];  
  let twiml = new Twilio.twiml.VoiceResponse();
  let blocked = true;
  if (blacklist.length > 0) {
    if (blacklist.indexOf(event.From) === -1) {
      blocked = false;
    }
  }
  if (blocked) {
    twiml.reject();
  }
  else {
  // if the caller's number is not blocked, redirect to your existing webhook
  twiml.redirect("https://handler.twilio.com/twiml/YOUR-WEBHOOK-URL");
  }
  callback(null, twiml);
};
