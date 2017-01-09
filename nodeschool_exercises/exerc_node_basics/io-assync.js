var fs = require('fs');

fs.readFile(process.argv[2], function(err, data){

	if(err){
		console.log('Error');
	}

	var array = data.toString().split('\n');

	console.log(array.length - 1);
});