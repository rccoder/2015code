var express = require('express');
var superagent = require('superagent');
var eventproxy = require('eventproxy');
var cheerio = require('cheerio');
var url = require('url');

var app = express();

var myUrl = 'http://www.rccoder.net/';
app.get('/', function(req, res, next){
	superagent.get(myUrl)
		.end(function(err, ress){
			if(err){
				return console.error(err);
				}
			var $ = cheerio.load(ress.text);
			var items = [];
			$('#post-list .fl').each(function(id, elem){
				var $elem = $(elem);
				var href = url.resolve(myUrl, $elem.attr('href'));
				items.push(href);
				});
				console.log(items);
			
	var ep = new eventproxy();
	ep.after('comment_html', items.length, function(comments){
		comments = comments.map(function(c){
			var commentUrl = c[0];
			var commentHtml = c[1];
			
			var $ = cheerio.load(commentHtml);
			
			return ({
				title: $('.ds-user-name').text().trim(),
				href: commentUrl,
				comment1: $('.ds-comment-header p').eq(0).text().trim(),
				});
			});
		console.log(comments);
			
		});
	items.forEach(function (commentUrl){
		superagent.get(commentUrl)
			.end(function(err, ress){
				ep.emit('comment_html', [commentUrl, ress.text]);
			});
	});
	

});
	});
app.listen(3001, function(){
	console.log('app is running!');
	});

