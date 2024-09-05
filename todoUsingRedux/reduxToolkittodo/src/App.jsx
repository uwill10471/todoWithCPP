
import './App.css'
import { store } from './app/store'
import {Provider} from 'react-redux'
import AddTodo from './components/AddTodo'
import Todos from './components/Todos'

function App() {
  

  return (
    
    <Provider store={store}>
     <h1>Learn about redux tool kit</h1>
     <AddTodo/>
     <Todos/>
     </Provider>
    
  )
}

export default App
