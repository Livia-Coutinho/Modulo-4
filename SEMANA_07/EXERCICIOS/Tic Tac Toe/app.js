const express = require('express');
const app = express();
const path = require('path');
const router = express.Router();

app.use(express.static(__dirname));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname+"/SevenMinutes.html")) 
});

app.listen(process.env.port || 3000);

console.log("funcionamento ok");

// //Aplicação utilizando Node.JS (Java Script no back-end)

// //Versão 8.5.0 (verificada da CMD com npm --v) 

// //npm init na pastas

// //Ligando o servidor:
// //Express- framework - rotas (npm install --save express)

// const http = require('http');

// const hostname = '127.0.0.1';
// const port = 3000; //(local)

// const server = http.createServer((req, res) => {  //servidor
//     res.statusCode = 200;
//     res.setHeader('Content-Type', 'text/plain');
//     res.end('Hello, Tic Tac Toe da Livia');

// }); 

// server.listen(port,hostname, () => {
//     console.log('funcionamento servidor ok')
// })

// //Node index.js     (servidor rodando!!!)


// //Como não está com nodemon para reload, é preciso ctrl + c no cmd e outro node index.js para exibir no localhost a versão recente do código.

