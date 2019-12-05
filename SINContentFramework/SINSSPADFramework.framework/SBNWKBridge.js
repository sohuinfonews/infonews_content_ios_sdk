/***************************************************************************
 * WKWebView native object
 **************************************************************************/
var WKWebViewNativeOBJ = window.webkit.messageHandlers;

var mraid = window.mraid = {};

//var log = {};
//log.i = function(msg) {
//    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("console://"+msg);
//}

window.alert = function (msg) {
    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("alert://"+msg);
}

window.comfirm = function (msg) {
    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("comfirm://"+msg);
}

window.prompt = function (msg) {
    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("prompt://"+msg);
}

var sbnlog = {};
// 之前有过一次被京东金融截获“log”方法，导致log之后的方法不执行。
sbnlog.i = function(msg) {
    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("console://"+msg);
}

console.log = function(msg){
    sbnlog.i("sym: "+msg);
}

var VERSION = "1.0";

mraid.version = function(){
    return VERSION;
}

mraid.platform = function(){
    return "ios";
}

mraid.getSign = function(params,callback){
    mraid.addEventListener(mraid.EVENTS.GETSIGN,callback);
    sbnCallNative("getSign?state=" + params);
}

mraid.copyToPasteboard = function(string,callback){
    mraid.addEventListener(mraid.EVENTS.PASTEBOARD,callback);
    sbnCallNative("copyToPasteboard?state=" + string);
}

mraid.getInvitationCode = function(callback){
    mraid.addEventListener(mraid.EVENTS.INVITATIONCODE,callback);
    sbnCallNative("getInvitationCode");
}

mraid.reloadHight = function(){
    // 不需要注册回调
    sbnCallNative("reloadHight");
}


mraid.userLogin = function(callback){
    mraid.addEventListener(mraid.EVENTS.USERLOGIN,callback);
    sbnCallNative("userlogin");
}

mraid.userTokenExpires = function(callback) {
    mraid.addEventListener(mraid.EVENTS.userTokenExpires,callback);
    sbnCallNative("userTokenExpires");
}

mraid.wakeupDisciple = function(title, image, url, text, callback){
    mraid.addEventListener(mraid.EVENTS.wakeupDisciple,callback);
    var params = {
        "title": title,
        "image": image,
        "url": url,
        "text": text,
    };
    sbnCallNative("wakeupDisciple?state="+ JSON.stringify(params));
}

mraid.scanContacts = function(callback) {
    mraid.addEventListener(mraid.EVENTS.scanContacts,callback);
    sbnCallNative("scanContacts");
}

mraid.lbsinfo = function(callback) {
    mraid.addEventListener(mraid.EVENTS.LBSINFO,callback);
   sbnlog.i("mraid.lbsinfo");
    sbnCallNative("lbsinfo");
}

mraid.authorizationStatus = function(type, callback) {
    mraid.addEventListener(mraid.EVENTS.authorizationStatus,callback);
    var params = {
        "type": type,
    }
    sbnCallNative("authorizationStatus?state="+ JSON.stringify(params));
}

mraid.sendMessage = function(params, callback){
    mraid.addEventListener(mraid.EVENTS.sendMessage,callback);
    sbnCallNative("sendMessage?state="+ JSON.stringify(params));
}

mraid.topicCallBack = function(params, callback){
    mraid.addEventListener(mraid.EVENTS.topicCallBack,callback);
    sbnCallNative("topicCallBack?data="+ JSON.stringify(params));
}

sbnlog.i("mraid init");

mraid.getVersion = function() {
   sbnlog.i("mraid.getVersion");
    return VERSION;
};

mraid.getStepsAuthority = function(callback){
    mraid.addEventListener(mraid.EVENTS.stepsAuthority,callback);
    sbnCallNative("getStepsAuthority");
}

mraid.setBarTitle = function(params) {
    sbnCallNative("setBarTitle?data="+params);
}

var EVENTS = mraid.EVENTS = {
    "ERROR" : "error",
    "READY" : "ready",
    "IsPOP" : 'isPop',
    "IsBecomeActive" : 'isBecomeActive',
    "DEVICEINFO" : 'deviceinfo',
    "USERINFO"   : 'userinfo',
    "LBSINFO"   : 'lbsinfo',
    "LOCATIONCHANGE": 'locationChange',
    "ORIENTATIONCHANGE": 'orientationChange',
    "NETWORKCHANGE": 'networkChange',
    "GETSIGN":'getSign',
    "PASTEBOARD":'copyToPasteboard',
    "INVITATIONCODE":'getInvitationCode',
    "USERLOGIN":'userlogin',
    "userTokenExpires":'userTokenExpires',
    "wakeupDisciple":'wakeupDisciple',
    "scanContacts":'scanContacts',
    "authorizationStatus":'authorizationStatus',
    "sendMessage":'sendMessage',
    "topicCallBack":'topicCallBack',
    "stepsAuthority" : 'getStepsAuthority'
};

// 初始化WebView
function webViewInit()
{
    
}

window.onload = webViewInit;

/***************************************************************************
 * "official" API: methods called by creative
 **************************************************************************/
var listeners = {};

mraid.addEventListener = function(event, listener) {
   sbnlog.i("mraid.addEventListener " + event + ": " + String(listener));
    if (!event || !listener) {
        mraid.fireErrorEvent("Both event and listener are required.", "addEventListener");
        return;
    }
    if (!contains(event, EVENTS)) {
        mraid.fireErrorEvent("Unknown MRAID event: " + event, "addEventListener");
        return;
    }
    var listenersForEvent = listeners[event] = listeners[event] || [];
    // check to make sure that the listener isn't already registered
    for (var i = 0; i < listenersForEvent.length; i++) {
        var str1 = String(listener);
        var str2 = String(listenersForEvent[i]);
        if (listener === listenersForEvent[i] || str1 === str2) {
           sbnlog.i("listener " + str1 + " is already registered for event " + event);
            return;
        }
    }
    changeEventNative(event, 1);
    listenersForEvent.push(listener);
};

mraid.removeEventListener = function(event, listener) {
   sbnlog.i("mraid.removeEventListener " + event + " : " + String(listener));
    if (!event) {
        mraid.fireErrorEvent("Event is required.", "removeEventListener");
        return;
    }
    if (!contains(event, EVENTS)) {
        mraid.fireErrorEvent("Unknown MRAID event: " + event, "removeEventListener");
        return;
    }
    if (listeners.hasOwnProperty(event)) {
        if (listener) {
            var listenersForEvent = listeners[event];
            // try to find the given listener
            var len = listenersForEvent.length;
            for (var i = 0; i < len; i++) {
                var registeredListener = listenersForEvent[i];
                var str1 = String(listener);
                var str2 = String(registeredListener);
                if (listener === registeredListener || str1 === str2) {
                    listenersForEvent.splice(i, 1);
                    break;
                }
            }
            if (i === len) {
               sbnlog.i("listener " + str1 + " not found for event " + event);
            }
            if (listenersForEvent.length === 0) {
                changeEventNative(event, 0);
                delete listeners[event];
            }
        } else {
            // no listener to remove was provided, so remove all listeners for given event
            delete listeners[event];
        }
    } else {
       sbnlog.i("no listeners registered for event " + event);
    }
};

/************************fire Event*******************************/
// methods to fire events

mraid.fireErrorEvent = function(message, action) {
   sbnlog.i("mraid.fireErrorEvent " + message + " " + action);
    fireEvent(mraid.EVENTS.ERROR, message, action);
};

mraid.fireReadyEvent = function() {
   sbnlog.i("mraid.fireReadyEvent");
    fireEvent(mraid.EVENTS.READY);
};

mraid.fireIsPopEvent = function(string) {
   sbnlog.i("fireIsPopEvent");
    fireEvent(mraid.EVENTS.IsPOP, string);
};
mraid.fireIsBecomeActiveEvent = function() {
   sbnlog.i("mraid.fireIsBecomeActiveEvent");
    fireEvent(mraid.EVENTS.IsBecomeActive);
};

mraid.fireDeviceEvent = function(string){
   sbnlog.i("mraid.fireDeviceEvent " + string);
    fireEvent(mraid.EVENTS.DEVICEINFO, string);
}

mraid.fireUserEvent = function(string){
   sbnlog.i("mraid.fireUserEvent " + string);
    fireEvent(mraid.EVENTS.USERINFO, string);
}

mraid.fireLBSEvent = function(string){
   sbnlog.i("mraid.fireLBSEvent " + string);
    fireEvent(mraid.EVENTS.LBSINFO, string);
    mraid.removeEventListener(mraid.EVENTS.LBSINFO,null);
}

mraid.fireSignEvent = function(string){
   sbnlog.i("mraid.fireSignEvent " + string);
    fireEvent(mraid.EVENTS.GETSIGN, string);
}

mraid.firePasteBoardEvent = function(string){
   sbnlog.i("mraid.firePasteBoardEvent " + string);
    fireEvent(mraid.EVENTS.PASTEBOARD, string);
    mraid.removeEventListener(mraid.EVENTS.PASTEBOARD,null);
}

mraid.fireInvitationCodeEvent = function(string){
   sbnlog.i("mraid.fireInvitationCodeEvent " + string);
    fireEvent(mraid.EVENTS.INVITATIONCODE, string);
    mraid.removeEventListener(mraid.EVENTS.INVITATIONCODE,null);
}

mraid.fireUserLoginEvent = function(string){
   sbnlog.i("mraid.fireUserLoginEvent " + string);
    fireEvent(mraid.EVENTS.USERLOGIN, string);
    mraid.removeEventListener(mraid.EVENTS.USERLOGIN,null);
}

mraid.fireUserTokenExpiresEvent = function(string){
   sbnlog.i("mraid.fireUserTokenExpiresEvent " + string);
    fireEvent(mraid.EVENTS.userTokenExpires, string);
    mraid.removeEventListener(mraid.EVENTS.userTokenExpires,null);
}

mraid.fireWakeupDisciple = function(string){
   sbnlog.i("mraid.fireWakeupDisciple " + string);
    fireEvent(mraid.EVENTS.wakeupDisciple, string);
    mraid.removeEventListener(mraid.EVENTS.wakeupDisciple,null);
}

mraid.fireScanContacts = function(string){
   sbnlog.i("mraid.fireScanContacts " + string);
    fireEvent(mraid.EVENTS.scanContacts, string);
    mraid.removeEventListener(mraid.EVENTS.scanContacts,null);
}

mraid.fireAuthorizationStatus = function(string){
   sbnlog.i("mraid.fireAuthorizationStatus " + string);
    fireEvent(mraid.EVENTS.authorizationStatus, string);
    mraid.removeEventListener(mraid.EVENTS.authorizationStatus,null);
}

mraid.fireSendMessage = function(string){
   sbnlog.i("mraid.fireSendMessage " + string);
    fireEvent(mraid.EVENTS.sendMessage, string);
    mraid.removeEventListener(mraid.EVENTS.sendMessage,null);
}

mraid.fireStepsAuthorityEvent = function(string){
    sbnlog.i("mraid.fireStepsAuthorityEvent " + string);
    fireEvent(mraid.EVENTS.stepsAuthority, string);
    mraid.removeEventListener(mraid.EVENTS.stepsAuthority,null);
}

function changeEventNative(event, state) {
    switch (event) {
        case EVENTS.DEVICEINFO:
            sbnCallNative("deviceinfo?state=" + state);
            break;
        case EVENTS.USERINFO:
            sbnCallNative("userinfo?state=" + state);
            break;
        case EVENTS.IsPOP:
            sbnCallNative("isPOPOpen?state=" + state);
           sbnlog.i("isPOPOpen");
            break;
        case EVENTS.LBSINFO:
            sbnCallNative("lbsinfo?state=" + state);
            break;
        case EVENTS.LOCATIONCHANGE:
            sbnCallNative("locationChange?state=" + state);
            break;
        case EVENTS.NETWORKCHANGE:
            sbnCallNative("networkChange?state=" + state);
            break;
        case EVENTS.ORIENTATIONCHANGE:
            sbnCallNative("orientationChange?state=" + state);
            break;
    }
}

/***************************************************************************
 * internal helper methods
 **************************************************************************/

var sbnCallNative = function(command) {
    WKWebViewNativeOBJ.SBNWebViewBridge.postMessage("mraid://"+command);
};

var fireEvent = function(event) {
    var args = Array.prototype.slice.call(arguments);
    args.shift();
   sbnlog.i("fireEvent " + event + " [" + args.toString() + "]");
    var eventListeners = listeners[event];
    if (eventListeners) {
        var len = eventListeners.length;
       sbnlog.i(len + " listener(s) found");
        for (var i = 0; i < len; i++) {
            eventListeners[i].apply(null, args);
        }
    } else {
       sbnlog.i("no listeners found");
    }
};

var contains = function(value, array) {
    for (var i in array) {
        if (array[i] === value) {
            return true;
        }
    }
    return false;
};

