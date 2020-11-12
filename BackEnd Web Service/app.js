const express = require('express');
const bodyParser = require('body-parser');

const app = express();

var statusC 

app.use(bodyParser.json());

app.get('/api/setCap1/:id', (req, res, next) => {
  let id = req.params.id;
  switch (id) {
    case '0':
      res.status(201).json({ Title : 'Capteur 1',
                             Status : '0',
                             Description : 'Capteur switched to OFF' });
      statusC = false;
      console.log(statusC);
      
      break;
    case '1':
      res.status(201).json({ Title : 'Capteur 1',
                             Status : '1',
                             Description : 'Capteur switched to ON' });
      statusC = true;        
      console.log(statusC);               
      break;
  
    default:
      res.status(404).json({ Title : 'Capteur 1',
                             Status : '',
                             Description : 'Error id not found' });
      console.log(statusC);
      break;
  }
  
  next();
});

app.get('/api/getAll', (req, res) => {
  console.log(statusC);
  res.json({ Title : 'Capteur 1',
             Status : ""+statusC})
})


module.exports = app;
