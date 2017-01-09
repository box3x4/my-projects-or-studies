var fs = require('fs');

module.exports = {

	fLs: function(path,ext, callback){

		fs.readdir(path,function(err,list){
			
			if(err){
				console.log('error');
				return callback(err);
			}

			var data = [];

			for(var i = 0;i<list.length;i++){

				var arr = list[i].split('.');

				if(arr.length-1 != 0)
					if(arr[arr.length-1] === ext)
						data.push(list[i]);
			}

			callback(null,data);
		});
	}

};