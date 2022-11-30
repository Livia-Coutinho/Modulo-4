const express = require('express');

const app = express();

const path = require('path');

const router = express.Router();

app.use(express.static(path.resolve(__dirname, './src')));

app.get('/', (req, res) => {
    res.render('src/App.jsx'); 
});

app.listen(process.env.port || 3000);

console.log("funcionamento ok");

