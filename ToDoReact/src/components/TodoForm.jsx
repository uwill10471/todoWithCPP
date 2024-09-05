import React, { useState } from "react";
import {useToDo} from '../context/todocontext'
export default function  TodoForm(){
    const [todo,setTodo] = useState("");
    const {addTodo}= useToDo()

    const add = (e) => {
        e.preventDefault()

        if(!todo) return
        addTodo({id: Date.now(),todo:todo,completed:false}) // we passin object cuz that is how we defined it 
        setTodo("") // remove the written todo from the bar
    }
    return (
        <form onSubmit={add} className="flex">
            <input
                type="text"
                placeholder="Write Todo..."
                className="w-full border border-black/10 rounded-l-lg px-3 outline-none duration-150 bg-white/20 py-1.5"
                value = {todo}
                onChange = {(e)=> setTodo(e.target.value)}
           />
            <button type="submit" className="rounded-r-lg px-3 py-1 bg-green-600 text-white shrink-0">
                Add
            </button>
        </form>
    )
}