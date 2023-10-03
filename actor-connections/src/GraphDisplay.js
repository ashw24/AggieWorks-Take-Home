import { useEffect } from 'react';
import * as d3 from 'd3';
import { useLocation, useNavigate } from 'react-router-dom';

function GraphDisplay() {
  const location = useLocation();
  const result = location.state?.result;
  const navigate = useNavigate();

  useEffect(() => {
    if (result) {
      const svg = d3.select(".result-svg");
      svg.selectAll("*").remove(); // Clear previous visualization
  
      // Parse the result string to get nodes and links
      const nodes = result.split(/[-()]+/).map((name, index) => ({ id: name.trim(), index }));
      const links = [];
      for (let i = 0; i < nodes.length - 1; i++) {
        links.push({ source: nodes[i].id, target: nodes[i + 1].id, movie: nodes[i + 1].id });
      }
  
      const simulation = d3.forceSimulation(nodes)
        .force("link", d3.forceLink(links).id(d => d.id))
        .force("charge", d3.forceManyBody())
        .force("center", d3.forceCenter(200, 200));
  
      const link = svg.append("g")
        .selectAll("line")
        .data(links)
        .enter().append("line");
  
      const linkLabels = svg.append("g")
        .selectAll("text")
        .data(links)
        .enter().append("text")
        .text(d => d.movie);
  
      const node = svg.append("g")
        .selectAll("circle")
        .data(nodes)
        .enter().append("circle")
        .attr("r", 5);
  
      const nodeLabels = svg.append("g")
        .selectAll("text")
        .data(nodes)
        .enter().append("text")
        .text(d => d.id);
  
      simulation.on("tick", () => {
        link.attr("x1", d => d.source.x)
            .attr("y1", d => d.source.y)
            .attr("x2", d => d.target.x)
            .attr("y2", d => d.target.y);
  
        linkLabels.attr("x", d => (d.source.x + d.target.x) / 2)
                  .attr("y", d => (d.source.y + d.target.y) / 2);
  
        node.attr("cx", d => d.x)
            .attr("cy", d => d.y);
  
        nodeLabels.attr("x", d => d.x)
                  .attr("y", d => d.y);
      });
    }
  }, [result]);

  return (
    <div>
      <svg className="result-svg" width="400" height="400"></svg>
      <div>{result}</div>
      <button onClick={() => navigate('/')}>Restart</button>
    </div>
  );
}
export default GraphDisplay;
