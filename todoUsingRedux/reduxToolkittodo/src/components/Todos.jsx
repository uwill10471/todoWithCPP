import React from "react";
import { useSelector , useDispatch} from "react-redux";
import {removeTodo} from '../features/todo/todoSlice'

export default function Todos(){
   const todos = useSelector((state) => state.todo.todos) //state.todos get todos from the initialState todos
//   const todos = useSelector((state )=> {
//     console.log(state.todos); // Log the state to check its structure
//     return state.todos || [];
// });
   const dispatch = useDispatch()
  
   
   return (
        <>
        <div>Todos</div>
            <ul>
        {todos.map((todo)=> (
        
            <li key={todo.id}>
                {todo.text}
                 <button onClick={()=>dispatch(removeTodo(todo.id))}>Delete</button>
            </li>
           
           
))}
 </ul>
        
        </>
    )
}