import { useState , useEffect} from "react"

import { TodoProvider } from "./context/todocontext"


import { TodoItem,TodoForm } from "../src/components/Index"


export default function App() {
  const [todos,setTodos] = useState([])
  const addTodo = (todo) => {
    setTodos((prev) => [...prev ,{id:Date.now(),...todo}]) //prev is used to store new value with the previous and thats why used spread operator ...prev so prev values will be their 
  }

  const updateTodo = (id,todo) => {
    setTodos((prev)=> prev.map((eachTodo) => (eachTodo.id === id ? todo : eachTodo))
  )}

  const deleteTodo = (id)=>{
    setTodos((prev)=> prev.filter((todo)=> todo!==id))
  }

  const toogleCompleted = (id) => {
    setTodos((prev) => prev.map((prevTodo) => prevTodo.id === id ? {...prev,completed: !prevTodo.completed}: prevTodo))
  }
 useEffect(()=>{
const todos = JSON.parse(localStorage.getItem("todos"))
if(todos && todos.length > 0){
  setTodos(todos)
}
 },[])
 
 useEffect(()=> {
  localStorage.setItem("todos" , JSON.stringify(todos))
 },[todos])

 // for next day have to make components 
  return (
    <TodoProvider value={{todos,addTodo,toogleCompleted,deleteTodo,updateTodo}}>  
   <div className="bg-[#172842] min-h-screen py-8">
                <div className="w-full max-w-2xl mx-auto shadow-md rounded-lg px-4 py-3 text-white">
                    <h1 className="text-2xl font-bold text-center mb-8 mt-2">Manage Your Todos</h1>
                    <div className="mb-4">
                        {/* Todo form goes here */} 
                        <TodoForm/>
                    </div>
                    <div className="flex flex-wrap gap-y-3">
                        {/*Loop and Add TodoItem here */}
                        {todos.map((todo) => {
                        //  console.log("hwew");
                          
                          <div key={todo.id}
                          className="w-full">
                            <TodoItem todo ={todo}/>
                          </div> //key is use to unqiuely identify
                          
                       
                       })}
                    </div>
                </div>
            </div>
     </TodoProvider>
  )
}