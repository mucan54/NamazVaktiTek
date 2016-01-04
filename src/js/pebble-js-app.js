var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};
var i=0;
var url;
var city;
var cityn;
var g1;
var g2;
var g3;
var g4;
var g5;
var keytoken = "";		// token to use for pushing items into the store
function log(text) {
	//console.log(text);
}
function getItem(key) {
	return localStorage.getItem('keepzer_' + key);
}

function storeItemKeepzer(gonder, trh, done) {
	log("Storing item");
	if (!keytoken) {
		keytoken = getItem('keytoken');
		if(!keytoken) {
			log("No keytoken available, cannot send.");
			if(done) done(0);
			return;
		}
		log("Send warning: Keytoken restored");
	}
	if (!gonder)
	{
		log("Cannot send empty json for item type ");
		if(done) done(3);
		return;
	}
}
  
function locationSuccess(pos) {
  // Construct URL
  
   if(i===0){
      url = "http://api.namazvakitleri.com.tr/searchCountriesAndCities/json/"+
          pos.coords.latitude +"/"+ pos.coords.longitude;}
  // Send request to OpenWeatherMap
  xhrRequest(url, 'GET', 
    function(responseText) {
      // responseText contains a JSON object with weather info
      var json = JSON.parse(responseText);
      var test = json.Info.Status;
      
      if(i===0)
        {
          city= json.Result[0].city_id;
          cityn = json.Result[0].city_name;
          url="http://api.namazvakitleri.com.tr/getTimes/json/"+city;
          i++;
          locationSuccess();
           console.log("AppMessage received!");
          return;
        }
      else if(test=="Success")
        {
          var dng,dmg;
           for(dng=7; dng<13; dng++){
                         if(dng!==7){ g1=g1+json.PrayerTimes[dng].date;}
             else{ g1=json.PrayerTimes[dng].date;}
                                     
                                g1=g1+json.PrayerTimes[dng].hDate;
                          g1=g1+json.PrayerTimes[dng].imsak;
                          g1=g1+json.PrayerTimes[dng].gunes;
                          g1=g1+json.PrayerTimes[dng].ogle;
                          g1=g1+json.PrayerTimes[dng].ikindi;
                          g1=g1+json.PrayerTimes[dng].aksam;
                          g1=g1+json.PrayerTimes[dng].yatsi;    
             dmg=dng;
           
                 dng=dng+6;
							g2=json.PrayerTimes[dng].date;           
                          g2=g2+json.PrayerTimes[dng].hDate;
                          g2=g2+json.PrayerTimes[dng].imsak;
                          g2=g2+json.PrayerTimes[dng].gunes;
                          g2=g2+json.PrayerTimes[dng].ogle;
                          g2=g2+json.PrayerTimes[dng].ikindi;
                          g2=g2+json.PrayerTimes[dng].aksam;
                          g2=g2+json.PrayerTimes[dng].yatsi;      
 
             
                 dng=dng+6;
							g3=json.PrayerTimes[dng].date;           
                          g3=g3+json.PrayerTimes[dng].hDate;
                          g3=g3+json.PrayerTimes[dng].imsak;
                          g3=g3+json.PrayerTimes[dng].gunes;
                          g3=g3+json.PrayerTimes[dng].ogle;
                          g3=g3+json.PrayerTimes[dng].ikindi;
                          g3=g3+json.PrayerTimes[dng].aksam;
                          g3=g3+json.PrayerTimes[dng].yatsi;      
 
                 dng=dng+6;
							g4=json.PrayerTimes[dng].date;           
                          g4=g4+json.PrayerTimes[dng].hDate;
                          g4=g4+json.PrayerTimes[dng].imsak;
                          g4=g4+json.PrayerTimes[dng].gunes;
                          g4=g4+json.PrayerTimes[dng].ogle;
                          g4=g4+json.PrayerTimes[dng].ikindi;
                          g4=g4+json.PrayerTimes[dng].aksam;
                          g4=g4+json.PrayerTimes[dng].yatsi;      
 
                 dng=dng+6;
							g5=json.PrayerTimes[dng].date;           
                          g5=g5+json.PrayerTimes[dng].hDate;
                          g5=g5+json.PrayerTimes[dng].imsak;
                          g5=g5+json.PrayerTimes[dng].gunes;
                          g5=g5+json.PrayerTimes[dng].ogle;
                          g5=g5+json.PrayerTimes[dng].ikindi;
                          g5=g5+json.PrayerTimes[dng].aksam;
                          g5=g5+json.PrayerTimes[dng].yatsi;      
             dng=dmg;
                 }
    
            console.log("Temperature is " +g1);
      storeItemKeepzer();
      // Assemble dictionary using our keys
      var dictionary = {
        "G1":g1,
          "G2":g2,
          "G3":g3,
          "G4":g4,
          "G5":g5,
          

      };
          

      // Send to Pebble
      Pebble.sendAppMessage(dictionary,
        function(e) {
          
          console.log("Weather info sent to Pebble successfully!");
        },
        function(e) {
          console.log("Error sending weather info to Pebble!");
        }
      );
        }}      
      );
}

function locationError(err) {
  console.log("Error requesting location!");
}

function getWeather() {
  navigator.geolocation.getCurrentPosition(
    locationSuccess,
    storeItemKeepzer,
    locationError,
    {timeout: 150000, maximumAge: 60000}
  );
}

// Listen for when the watchface is opened
Pebble.addEventListener('ready', 
  function(e) {
    console.log("PebbleKit JS ready!");

    // Get the initial weather
    getWeather();
  }
);

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log("AppMessage received!");
    getWeather();
  }                     
);
