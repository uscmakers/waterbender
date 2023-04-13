import Grid from "./Grid"
import { PaintContextProvider } from "./paintContext"
import Pallette from "./Pallette"
import axios from "axios"

const onSubmit = async () => {
  axios
    .get("http://localhost:8080/getAll/")
    .then((response) => {
      console.log(response.data)
    })
    .catch(function (error) {
      console.log(error)
    })
}

function App() {
  return (
    <div>
      <div class="header">
        <h1>Waterbender Drawing App</h1>
      </div>
      <PaintContextProvider>
        <div className="outer">
          <div className="inner">
            <Grid />
          </div>
          <div className="side-panel">
            <Pallette />
            <button onClick={onSubmit}>
              Submit Drawing
            </button>
          </div>
        </div>
      </PaintContextProvider>
    </div>
  )
}

export default App
