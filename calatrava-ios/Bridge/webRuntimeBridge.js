var calatrava = calatrava || {};
calatrava.bridge = calatrava.bridge || {};

calatrava.bridge.args = (function() {
  var nextArgId = 0, argStore = {};

  var store = function(argArray) {
    var argId = nextArgId;

    argStore[argId] = argArray;
    nextArgId += 1;
    
    return argId;
  };

  var retrieve = function(argId) {
    var args = argStore[argId];
    delete argStore[argId];
    return args;
  };

  return {
    store: store,
    retrieve: retrieve
  };
}());

calatrava.bridge.native = {

  getArgs: function(argId) {
    return JSON.stringify(calatrava.bridge.args.retrieve(argId));
  }

};

calatrava.bridge.runtime = {
  renderProxy: function(viewObject, proxyId) {
    // Clean off properties that cause problems when marshalling
    if (viewObject.hasOwnProperty('toJSONString')) {
      viewObject.toJSONString = null;
    }
    if (viewObject.hasOwnProperty('parseJSON')) {
      viewObject.parseJSON = null;
    }

    // Delete any keys that have a null value to avoid the Obj-C JSON
    // serialization failure
    if (viewObject != undefined) {
      calatrava.bridge.support.cleanValues(viewObject);
    }
      
      nativeRuntime.renderWith(proxyId, viewObject);
  },

  issueRequest: function(options) {
      nativeRuntime.requestFromUrlAsWithHeaders(options.requestId,options.url,options.method,options.body,options.headers);
  }
};

var methods = ["log",
  "attachProxyEventHandler",
  "startTimerWithTimeout",
  "openUrl",
  "callPlugin"];

for (m in methods) {
  if (methods.hasOwnProperty(m)) {
    (function(method) {
      calatrava.bridge.runtime[method] = function() {
        var callArgs = [method].concat(_.toArray(arguments));
        calatrava.bridge.native.call.apply(calatrava.bridge.native, callArgs);
      };
    }(methods[m]));
  }

calatrava.bridge.runtime.callPlugin = function (pluginName, method, argMessage) {
    nativeRuntime.callPluginMethodWithArgs(pluginName,method,argMessage);
}

calatrava.bridge.runtime.changePage = function(target) {
    nativeRuntime.changeToPage(target);
}

calatrava.bridge.runtime.registerProxyForPage = function(proxyId, pageName) {
    nativeRuntime.registerProxyForPage(proxyId, pageName);
}

calatrava.bridge.runtime.attachProxyEventHandler = function(proxyId, event) {
    nativeRuntime.attachHandlerToForEvent(proxyId, event);
}

calatrava.bridge.runtime.valueOfProxyField = function(proxyId, field, event) {
    nativeRuntime.valueFromForFieldReturnedTo(proxyId,field,event);
}


calatrava.bridge.support = {
  cleanValues: function(jsObject) {
    _.each(_.keys(jsObject), function(key) {
      if (jsObject[key] === null || jsObject[key] === undefined) {
        delete jsObject[key];
      } else if (jsObject[key] === false) {
        jsObject[key] = 0;
      } else {
        if (jsObject[key] instanceof Object) {
          calatrava.bridge.support.cleanValues(jsObject[key]);
        }
      }
    });
  }
};
