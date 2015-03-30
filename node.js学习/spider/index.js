var express = require('express');
var superagent = require('superagent');
var cheerio = require('cheerio');

var app = express();

app.get('/', function(req, res, next){
	superagent.get('http://www.rccoder.net/')
		.end(function(err, ress){
			if(err){
				return next(err);
				}
			var $ = cheerio.load(ress.text);
			var items = [];
			$('#post-list .post-list .post-list-title .fl').each(function(i, elem){
				var $elem = $(elem);
				items.push({
					title: $elem.attr('title'),
					href: $elem.attr('href')
					});
				});
				res.send(items);
			});
	});
app.listen(3000, function(){
	console.log('app is running!');
	});
