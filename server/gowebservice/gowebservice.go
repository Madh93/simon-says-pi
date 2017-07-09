package main

import (
	"github.com/ant0ine/go-json-rest/rest"
	"gopkg.in/mgo.v2"
        "gopkg.in/mgo.v2/bson"
	"log"
	"fmt"
	"net/http"
)

type game struct {

  PlayerName string `json:"name" bson:"name"`
  Score int         `json:"score" bson:"score"`
  Timestamp   string   `json:"timestamp" bson:"timestamp"`

}

func main() {
	session, err := mgo.Dial("db")
	if err != nil {

			panic(err)
	}
	defer session.Close()

	session.SetMode(mgo.Monotonic, true)

	//c := session.DB("simon").C("games")

	api := rest.NewApi()
	api.Use(rest.DefaultDevStack...)
	router, err := rest.MakeRouter(
		rest.Get("/games", GetAllGames),
		rest.Post("/games", PostGame),
		rest.Get("/games/:code", GetGame),
		rest.Get("/topscores", GetTopScores),
		rest.Delete("/games/:code", DeleteGame),
	)
	if err != nil {
		log.Fatal(err)
	}
	api.SetApp(router)
	log.Fatal(http.ListenAndServe(":8080", api.MakeHandler()))
}

func GetGame(w rest.ResponseWriter, r *rest.Request) {
	result := game{}
	code := r.PathParam("code")

	session, err := mgo.Dial("db")
	c := session.DB("simon").C("games")

	err = c.Find(bson.M{"name": code}).One(&result)
	fmt.Printf("%+v\n", result)

	if err != nil {
		panic(err)
	}

	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteJson(&result)
}

func GetAllGames(w rest.ResponseWriter, r *rest.Request) {
	fmt.Println("getallgames method")
	result := []game{}
	session, err := mgo.Dial("db")
	c := session.DB("simon").C("games")
	err = c.Find(nil).All(&result)

	if err != nil {
		panic(err)
	}

	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteJson(&result)
}

func PostGame(w rest.ResponseWriter, r *rest.Request) {
	game := game{}
	err := r.DecodeJsonPayload(&game)
	session, err := mgo.Dial("db")
	c := session.DB("simon").C("games")
	err = c.Insert(game)

	if err != nil {
		panic(err)
	}
}

func DeleteGame(w rest.ResponseWriter, r *rest.Request) {
	code := r.PathParam("code")
	session, err := mgo.Dial("db")
	if err != nil {
		panic(err)
	}
	c := session.DB("simon").C("games")
	err = c.Remove(bson.M{"name": code})
	w.WriteHeader(http.StatusOK)
}

func GetTopScores(w rest.ResponseWriter, r *rest.Request) {
	result := []game{}
	session, err := mgo.Dial("db")
	c := session.DB("simon").C("games")
	err = c.Find(nil).Sort("-score").Limit(10).All(&result)

	if err != nil {
		panic(err)
	}

	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteJson(&result)
}
