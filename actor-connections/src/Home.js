import { useState } from 'react';
import { useNavigate } from 'react-router-dom';

function Home() {
  const [actor1, setActor1] = useState('');
  const [actor2, setActor2] = useState('');
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    const handleSubmit = async (e) => {
      e.preventDefault();
      try {
        const response = await fetch(`http://localhost:18080/getDegrees?actor1=${actor1}&actor2=${actor2}`);
        if (!response.ok) {
          throw new Error(`HTTP error! Status: ${response.status}`);
        }
        const data = await response.json();
        navigate('/graph', { state: { result: data.result } });
      } catch (error) {
        console.error("Error fetching data:", error);
        // Handle the error as you see fit, maybe set an error state and display it to the user
      }
    };
    
      
  };

  return (
    <div>
      <h1>Actor Connections</h1>
      <p>Enter two actor names to find their connection.</p>
      <form onSubmit={handleSubmit}>
        <input
          value={actor1}
          onChange={(e) => setActor1(e.target.value)}
          placeholder="First actor"
          required
        />
        <input
          value={actor2}
          onChange={(e) => setActor2(e.target.value)}
          placeholder="Second actor"
          required
        />
        <button type="submit">Submit</button>
      </form>
    </div>
  );
}
export default Home;

