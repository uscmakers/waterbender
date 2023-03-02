const express = require("express");
 
// recordRoutes is an instance of the express router.
// We use it to define our routes.
// The router will be added as a middleware and will take control of requests starting with path /record.
const Routes = express.Router();
 
// This will help us connect to the database
const dbo = require("./conn");
 
// This help convert the id from string to ObjectId for the _id.
const ObjectId = require("mongodb").ObjectId;
 
 
// This section will help you get a list of all the records.
Routes.route("/getDrawing").get(function (req, res) {
 let db_connect = dbo.getDb("Waterbender");
 db_connect
   .collection("Drawings")
   .findOne({}, function (err, result) {
    if (err) throw err;
    res.json(result);
  });
});

Routes.route("/getAll").get(function (req, res) {
  let db_connect = dbo.getDb("Waterbender");
  db_connect
    .collection("Drawings")
    .find({})
    .toArray(function (err, result) {
      if (err) throw err;
      res.json(result);
    });
 });

Routes.route("/sendDrawing").post(function (req, res) {
  let db_connect = dbo.getDb("Waterbender");
  let drawing = {
    image : req.body.image,
  }
  db_connect
    .collection("Drawings")
    .insertOne(drawing, function (err, result) {
      if (err) {
        throw err;
      }
      res.json(result);
    })
 });
 
module.exports = Routes;