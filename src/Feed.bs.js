// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Axios = require("axios");
var React = require("react");

function Feed(Props) {
  var name = Props.name;
  var match = React.useState((function () {
          return "";
        }));
  var setItems = match[1];
  React.useEffect((function () {
          Axios.get("https://hacker-news.firebaseio.com/v0/topstories.json").then((function (response) {
                    return Promise.resolve(Curry._1(setItems, response.data));
                  })).catch((function (error) {
                  return Promise.resolve((console.log(error), /* () */0));
                }));
          return (function (param) {
                    console.log(/* () */0);
                    return /* () */0;
                  });
        }), ([]));
  var message = "hello " + name;
  return React.createElement("div", undefined, match[0], message);
}

var make = Feed;

exports.make = make;
/* axios Not a pure module */
