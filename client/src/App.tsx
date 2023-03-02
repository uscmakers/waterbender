import Grid from "./Grid";
import { PaintContextProvider } from "./paintContext";
import Pallette from "./Pallette";
import axios from "axios";

const onSubmit = async () => {
  axios.get("http://localhost:8080/getAll/").then((response) => {
      console.log(response.data);
    })
    .catch(function (error) {
      console.log(error);
    });
}

function App() {
  return (
    <div>
     <PaintContextProvider>
        <div className="outer">
          <div className="inner">
            <Grid />
          </div>
          <Pallette />
        </div>
      </PaintContextProvider>
      <button onClick={onSubmit}>
        Submit Drawing
      </button>
    </div>
  );
}

export default App;
