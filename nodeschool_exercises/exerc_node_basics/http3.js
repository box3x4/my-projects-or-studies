var http = require('http');
var bl = require('bl');

http.get(process.argv[2], function(res){

	res.pipe(bl(function(err, data){
		console.log(data.toString());
	}));

	res.on('end', function(){

		http.get(process.argv[3], function(res2){

			res2.pipe(bl(function(err2, data2){
				console.log(data2.toString());
			}));

			res2.on('end', function(){

				http.get(process.argv[4], function(res3){

					res3.pipe(bl(function(err3,data3){
						console.log(data3.toString());
					}));
				});
			});
		});
	});
});