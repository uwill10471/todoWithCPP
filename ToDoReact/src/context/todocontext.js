import react from 'react'
import { createContext,useContext } from 'react'

export const Todocontext = createContext({
    Todo : [
        {
            id:1,
            todo:"todo msg",
            completed:false
        }
    ],
    addTodo: (todo) =>{},
    updateTodo: (id,todo) => {},
    deleteTodo: (id)=>{},
    toogleCompleted: (id)=>{}
})

export const TodoProvider = Todocontext.Provider

export const useToDo = ()=>{
    return useContext(Todocontext)
}