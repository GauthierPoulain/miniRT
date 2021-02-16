const fs = require("fs");
const color = "255,255,255";
var file;

async function read_file(path) {
	return new Promise(async (resolve) => {
		fs.readFile(path, "utf-8", (err, data) => {
			if (err) throw err.message;
			else file = data;
			resolve();
		});
	});
}

async function add_line(path, line) {
	return new Promise((resolve) => {
		fs.appendFile(path, line, (err) => {
			if (err) throw err.message;
			else resolve();
		});
	});
}

async function remove_file_if_exist(path) {
	return new Promise((resolve) => {
		try {
			fs.unlink(path, () => {
				resolve;
			});
		} catch (err) {
			resolve();
		}
	});
}

main(process.argv.slice(2));

async function main(args) {
	if (!args[0] || !args[0].endsWith(".obj")) {
		console.log("node index.js <file.obj>");
		return;
	}
	let path = args[0];
	let respath = `${path.substr(0, path.lastIndexOf("."))}.rt`;
	remove_file_if_exist(respath);
	await read_file(path);
	file = file.replace(/\r/g, "");
	file = file.split("\n");
	add_line(respath, "R	500	500\nA	.2	255,255,255\nc	0,5,-20		0,0,0	70\nl	2,10,-20	.8	0,255,255\n")
	let local = 0;
	let newline = "";
	for (const element of file) {
		let line = element;
		if (
			line.startsWith("v") &&
			!(line.startsWith("vn") || line.startsWith("vt"))
		) {
			line = line.substring(2).split(" ").join(",");
			newline += ` ${line}`;
			local++;
			if (local == 3) {
				newline = `tr ${newline} ${color}\n`;
				await add_line(respath, newline);
				local = 0;
				newline = "";
			}
		}
	}
	console.log(`${respath} done`);
}
