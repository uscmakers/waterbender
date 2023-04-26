import { useEffect, useRef, useState } from "preact/hooks";
import Pixel from "./Pixel";
import axios from "axios"


//  a grid component that fills the screen with Pixel components
var pixelTest = Array<Array<string>>;
const width = 23; //Math.floor(ref.current!.clientWidth / 16);
const height = 23; //Math.floor(ref.current!.clientHeig ht / 16);

const Gird = () => {
  const ref = useRef<HTMLDivElement>(null);

  // array of Pixel components to render a grid
  const [pixels, setPixels] = useState<Array<JSX.Element>>([]);

  useEffect(() => {
    var test = Array.from(Array(height+1), () => Array(width+1).fill("#fff"));
    // create a two dimensional array of Pixel components
    const grid: typeof pixels = [];

    for (let x = 1; x <= width; x++) {
      for (let y = 1; y <= height; y++) {
        grid.push(<Pixel x={x} y={y} color="#fff" grid={test}/>);
      }
    }

    // set the grid
    setPixels(grid);
  }, []);

  const onSubmitTest = async () => {
    var art = Array.from(Array(height), () => Array(width).fill(0));
    var pixelGrid = pixels[0].props.grid;
    for (let x = 1; x <= width; x++) {
      for (let y = 1; y <= height; y++) {
          if (pixelGrid[x][y] != '#fff') {
            art[x-1][y-1] = 1;
          }
      }
    }

    console.log(art);
    // Send data to MongoDB
    let drawing = {
      image: art,
    }
    axios.post("http://localhost:8080/sendDrawing/", drawing).then((response) => {
      console.log(response.data);
      window.location.reload();
    })
    .catch(function (error) {
      console.log(error);
      window.alert("Failed to set image")
    });
  }

  return (
    <div>
      <div ref={ref} className="grid">
        {pixels}
      </div>
      <div>
        <button onClick={onSubmitTest} className="button">
                Submit Drawing
        </button>
      </div>
    </div>
  );
};

export default Gird;
