// Importing necessary libraries and components
import React, { useState, useEffect } from 'react';
import { BrowserRouter as Router, Route, Link, useHistory } from 'react-router-dom';
import './App.css';
import * as d3 from 'd3';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faUser, faRandom, faSearch, faFilm, faRedo } from '@fortawesome/free-solid-svg-icons';

// Main component for the application
function Main() {
  // State for showing the loading spinner
  const [showLoading, setShowLoading] = useState(false);

  // Sample list of actors
  const actorList = [  "Chad_Oliphant", "Chelsea_Goodwin",
  "Peter_Greene", "Alice_Ensor",
  "William_Quinn", "Erica_Manni",
  "Joseph_Aviel", "Michael_Blum",
  "Dylan_Jordan", "Gift_Harris",
  "Tanja_Spiess", "B.R._Jayaram",
  "Albertine_Green", "Emily_Towles",
  "Justin_Devine", "Mike_Nall",
  "Frank_G.W._Thomas", "Seve_Williams",
  "Evan_Stern", "Giovanni_Savoia",
  "Justin_Rose", "Randy_Mars",
  "Carolyn_Blashek", "Brisa_Delaselva",
  "Louis_Fasanaro", "John_Sarkisian",
  "Eugene_Moore", "William_S._Benson",
  "Michael_Cotten", "John_Wuchte",
  "Charles_Bartlett", "Carrie_Stevens",
  "BeBe_Bellamont", "Jenna_Enns",
  "Kenneth_Chang", "Adam_C._Johnson",
  "Haskell_V._Anderson_III", "Melissa_Mars",
  "Helen_Holmes", "Diana_Mickelson",
  "Nicole_Signore", "Larry_Wellington_Cauldwell_III",
  "Silent_Addy", "Anton_Weidner",
  "Laura_Vandervoort", "Tedd_Saint-James",
  "Sylvester_Little_Jr.", "Christine_Bennett",
  "Colleen_Irene_Boag", "Jack_Mercer",
  "Allex_Jording", "Cary_Y._Mizobe",
  "Premstar_Santana", "Deanne_Destler",
  "Michiko_Hoshi", "Frank_Riley",
  "Carlyle_Blackwell", "Sammy_Anderson",
  "Mar_Omega", "Michael_Mulvey",
  "Douglas_Graves", "Lloyd_Hamilton",
  "Jared_Fansler", "Pablo_Patlis",
  "Ron_Pacheco", "Bill_Lobley",
  "Paris_Brown", "Karen_Kahler",
  "Jeffrey_B._Campbell", "Steve_Aaron",
  "Ted_Chun", "Patrick_Foy",
  "Emily_Baldoni", "Marielle_Scott",
  "Natalie_Smyka", "Janine_Cogelia",
  "Leslie_Frye", "Scott_Mielock",
  "Jee_Mee_Kim", "Clara_Perryman",
  "Camille_Cristobal", "Julie_Mann",
  "Mike_Sutton", "Yisrael_Meir_Jacobson",
  "Amanda_Madison", "Paul_Lieber",
  "Andrew_Sensenig", "Kacie_Houston",
  "Ntxawm_Hawj", "Florence_Vidor",
  "Cassie_Stewart", "Ryder_Londo",
  "Brian_Veronica", "Tierney_Acott",
  "Brandon_Parham", "Eric_Bachmann",
  "Cameron_Ring", "Allen_Schwarts",
  "Amy_Jo_Jackson", "Tracy_Jack",
  "Renee_Iovine", "Derek_Bauman",
  "Cody_Lyle_Asher", "Kenny_Bordes",
  "Radha_Mitchell", "Briana_Bradley",
  "Maria_Cavassuto", "Lucas_Cardona",
  "Matt_Willis", "Bill_Lee_Brown",
  "Linda_Smith", "Tanner_Smith",
  "Hakym_Reagan", "Merlin_Senthil",
  "Thai_Edwards", "Michael_C._Maronna",
  "Ari_Joffe", "Conner_Marx",
  "Yosef_Podolski", "Frank_Hallack",
  "Catesby_Bernstein", "Emily_McVey",
  "Chanon_Finley", "Brad_Whitford",
  "Kyle_Kaiser", "D'Ercey_Smith",
  "Lezlie_Williams", "Sally_Leung_Bayer",
  "Dakota_Carter", "Cindy_Gilbert",
  "Ethan_Ednee", "Keith_Bisset",
  "Paula_Taylor", "Kathlyn_Williams",
  "Malcolm_Sebastian", "Taylor_Hill",
  "Erin_Carufel", "Daniel_Munarth",
  "Cooper_Barnes", "Tom_Powers",
  "Anthony_Reynolds", "Robert_John_Burke",
  "Emily_Mura-Smith", "Lafe_McKee",
  "Jennifer_Hare", "Chelsea_Spirito",
  "Matthew_Webb", "Joel_Clark_Ackerman",
  "Brian_Chamberlain", "Owen_Hirst",
  "Ingemar_Johansson", "Javi_Mulero",
  "James_Hurley", "Stephen_L._Burns",
  "Beyoncé", "Caroline_Goodall",
  "Joy_Kim", "Benjamin_Charles",
  "Laura_Fantuzzi", "Krystal_Willis",
  "Rachel_Casparian", "Apryl_Wilson",
  "Richard_Taylor", "Frank_Newburg",
  "Mila_Kunis", "Michael_Kaczurak",
  "Evan_King", "John_Bellemer",
  "Kristina_Jovanovic", "Jen_Gentile",
  "Gary_Kozak", "Margaret_Morris",
  "Santino_Craven", "Tadd_Morgan",
  "Christina_Leone", "Kara_Nova",
  "Jackson_Parker", "Scott_Ganyo",
  "Jeff_Hoferer", "Spencer_Kane",
  "Irene_Ong", "Juan_Barbieri",
  "S._David_Nieves", "Catherine_Campion",
  "Rebecca_Kenny", "Ernest_Thomas",
  "Jeffery_Battersby", "Trevor_Earley",
  "Wesley_Reymond", "Porfirio_Díaz",
  "Lauren_Lox", "Jeffrey_M._Hartman",
  "Nick_White", "Jared_Haus",
  "Michael_Vachetti", "Kelsey_Crane",
  "Julie_Gonzalo", "Jack_Connolly",
  "Hope_Sender", "James_Wong",
  "Alicia_An_Clark", "Aaron_Diskin",
  "Chauncey_Depew", "Blanche_Bayliss",
  "Chauncey_Depew", "Chauncey_Depew",
  "Hannah_D._Scott", "Hannah_D._Scott" ];

  // Function to get a random actor from the list
  const getRandomActor = () => {
    const randomIndex = Math.floor(Math.random() * actorList.length);
    return actorList[randomIndex];
  };

  // Function to set two random actors
  const setRandomActors = () => {
    setActor1(getRandomActor());
    setActor2(getRandomActor());
  };

  // States for the two actors
  const [actor1, setActor1] = useState('');
  const [actor2, setActor2] = useState('');

  // For navigation
  const history = useHistory();

  // Helper function to format actor names for the request
  const formatForRequest = (name) => {
    return name.replace(/\s+/g, '_');
  };

  // Function to handle form submission
  const handleSubmit = async (e) => {
    e.preventDefault();
    setShowLoading(true); // Show loading spinner

    try {
      const formattedActor1 = formatForRequest(actor1);
      const formattedActor2 = formatForRequest(actor2);
      const response = await fetch(`http://localhost:18080/getDegrees?actor1=${formattedActor1}&actor2=${formattedActor2}`);
      const data = await response.json();
      history.push("/results", { result: data.result });
    } catch (error) {
      console.error("Error fetching data:", error);
      setShowLoading(false); // Hide loading spinner on error
    }
  };

  // Render the main component
  return (
    <div className="App">
      <h1>Six Degrees of Kevin Bacon</h1>
      <div className="paragraph-container">
        <p>
          This website allows users to explore connections between actors in movies. Simply enter the names of two actors, or use the "Set Random Actors" button for a random pair, and discover the cinematic links that connect them through a visually engaging graph.
        </p>
      </div>
      <form onSubmit={handleSubmit}>
        <input value={actor1} onChange={(e) => setActor1(e.target.value)} placeholder="First actor" required />
        <input value={actor2} onChange={(e) => setActor2(e.target.value)} placeholder="Second actor" required />
        <button type="submit">
          <FontAwesomeIcon icon={faSearch} /> Submit
        </button>
        <button className="random-button" onClick={setRandomActors}>
          <FontAwesomeIcon icon={faRandom} /> Set Random Actors
        </button>
      </form>

      {showLoading && <Loading />} 
    </div>
  );
}

// Loading component to show while fetching data
function Loading({ onComplete }) {
  const loadingText = [  'Loading...',
  'Please wait...',
  'Fetching data...',
  'Analyzing connections...', ];
  const [loadingMessage, setLoadingMessage] = useState('');

  useEffect(() => {
    const randomIndex = Math.floor(Math.random() * loadingText.length);
    setLoadingMessage(loadingText[randomIndex]);
    const loadingTime = Math.floor(Math.random() * (60000 - 30000)) + 30000;
    const timer = setTimeout(() => {
      if (onComplete) {
        onComplete();
      }
    }, loadingTime);
    return () => clearTimeout(timer);
  }, [onComplete]);

  return (
    <div className="loading-container">
      <p className="loading-message">{loadingMessage}</p>
      <div className="loading-bar-container">
        <div className="loading-bar"></div>
      </div>
    </div>
  );
}

// Component to show the loading page
function LoadingPage() {
  const history = useHistory();
  const handleLoadingComplete = () => {
    history.push("/results");
  };
  return (
    <div className="App">
      <Loading onComplete={handleLoadingComplete} />
    </div>
  );
}

// Component to show the results
function Results({ location }) {
  const [result, setResult] = useState(location.state.result);
  const [width, setWidth] = useState(window.innerWidth * 0.9);
  const [height, setHeight] = useState(window.innerHeight * 0.9);
  const [noConnections, setNoConnections] = useState(false);
  const history = useHistory();

  useEffect(() => {
    if (result) {
      const svg = d3.select(".result-svg");
      svg.selectAll("*").remove(); // Clear previous visualization

      // Parse the result string to get nodes and links
      const segments = result.split(/[-()]+/).map(segment => segment.trim());

      const nodes = [];
      const links = [];

      for (let i = 0; i < segments.length - 1; i += 2) {
        const sourceName = segments[i];
        const movieName = segments[i + 1];
        const targetName = segments[i + 2];

        // Add source and target nodes if they don't exist
        if (!nodes.some(node => node.id === sourceName)) {
          nodes.push({ id: sourceName });
        }
        if (i + 2 < segments.length && !nodes.some(node => node.id === targetName)) {
          nodes.push({ id: targetName });
        }

        // Add the link (movie)
        if (i + 2 < segments.length) {
          links.push({ source: sourceName, target: targetName, movie: movieName });
        }
      }

      if (nodes.length === 0 || links.length === 0) {
        // If there are no nodes or links, set the 'noConnections' state to true
        setNoConnections(true);
      } else {
        setNoConnections(false); // Reset 'noConnections' state
        setWidth(Math.max(window.innerWidth, nodes.length * 600));
        setHeight(window.innerHeight * 0.9);
        
        let xOffset = -500;
        const horizontalSpacing = 400; // Increase this value to spread out the nodes more

      nodes.forEach((node, i) => {
      
          // Position other nodes relative to the first node in a zigzag pattern
          xOffset += horizontalSpacing;
          node.fx = window.innerWidth / 2 + xOffset;
          if (i % 2 === 0) {
            node.fy = (window.innerHeight / 2) + 150;  // 150 is the offset, can be adjusted
          } else {
            node.fy = (window.innerHeight / 2) - 150;  // negative offset for zigzag pattern
          }

      });

      const mutedColors = ["#a6cee3", "#b2df8a", "#fb9a99", "#fdbf6f", "#cab2d6", "#ffff99", "#1f78b4", "#33a02c", "#e31a1c", "#ff7f00"];
      const colorScale = d3.scaleOrdinal(mutedColors);

      const simulation = d3.forceSimulation(nodes)
        .force("link", d3.forceLink(links).id(d => d.id).distance(1000))
        .force("charge", d3.forceManyBody().strength(-10000));
      const formatName = (name) => {
          return name.replace(/_/g, ' ');
        };
        const link = svg.append("g")
        .selectAll("line")
        .data(links)
        .enter().append("line")
        .attr("stroke", "#000")
        .attr("stroke-width", 2)
        .attr("marker-end", "url(#arrow)");
      
      const linkLabels = svg.append("g")
        .selectAll("text")
        .data(links)
        .enter().append("text")
        .text(d => formatName(d.movie))
        .attr("text-anchor", "middle")
        .attr("dy", "-10");
      
        const node = svg.append("g")
        .selectAll("circle")
        .data(nodes)
        .enter().append("circle")
        .attr("r", d => Math.max(20, d.id.length * 5))
        .attr("fill", d => colorScale(d.id)); // Use the muted color scale
      
      const nodeLabels = svg.append("g")
        .selectAll("text")
        .data(nodes)
        .enter().append("text")
        .text(d => formatName(d.id))
        .attr("text-anchor", "middle")
        .attr("dy", ".35em");
      const computeAngle = (source, target) => {
          const dx = target.x - source.x;
          const dy = target.y - source.y;
          const angle = Math.atan2(dy, dx) * (180 / Math.PI);
          return angle;
        };
        
      simulation.on("tick", () => {
        link.attr("x1", d => d.source.x)
            .attr("y1", d => d.source.y)
            .attr("x2", d => d.target.x)
            .attr("y2", d => d.target.y);

        linkLabels.attr("x", d => (d.source.x + d.target.x) / 2)
            .attr("y", d => (d.source.y + d.target.y) / 2)
            .attr("transform", d => {
              const angle = computeAngle(d.source, d.target);
              const x = (d.source.x + d.target.x) / 2;
              const y = (d.source.y + d.target.y) / 2;
              return `rotate(${angle}, ${x}, ${y})`;
            });

        node.attr("cx", d => d.x)
            .attr("cy", d => d.y);

        nodeLabels.attr("x", d => d.x)
                  .attr("y", d => d.y);
      });

      }
    }
  }, [result]);

  const getBoxSize = () => {
    if (noConnections) {
      return { width: 400, height: 400 }; // Set a fixed box size when no connections
    } else {
      return { width, height }; // Use the calculated size when there are connections
    }
  };

  const handleRestart = () => {
    history.push("/");
  };

  return (
    <div className="App">
      {noConnections ? (
        <p>No connections found.
          <button onClick={handleRestart} className="refresh-button2">
            <FontAwesomeIcon icon={faRedo} /> Restart
          </button>
        </p>
      ) : (
        <div className="graph-scroll-container">
          <div className="graph-container" style={getBoxSize()}> 
            <svg className="result-svg" width={width} height={height}>
              <defs>
                <marker id="arrow" markerWidth="10" markerHeight="10" refX="20" refY="3" orient="auto" markerUnits="strokeWidth">
                  <path d="M0,0 L0,6 L9,3 z" fill="#f00" />
                </marker>
              </defs>
            </svg>
            <button onClick={handleRestart} className="refresh-button">
              <FontAwesomeIcon icon={faRedo} /> Restart
            </button>
          </div>
        </div>
      )}
    </div>
  );
}

// Main App component that sets up routing
function App() {
  return (
    <Router>
      <Route path="/" exact component={Main} />
      <Route path="/loading" exact component={LoadingPage} /> 
      <Route path="/results" component={Results} />
    </Router>
  );
}

export default App;
