external _toArray : 'a => Js.Promise.t (array 'b) = "stream-to-array" [@@bs.module];
let toArray (stream : NodeFs.Readable.t _ 'data) : Js.Promise.t (array 'data)
    => _toArray (NodeFs.Readable.unbox stream);