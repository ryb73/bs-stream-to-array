external _toArray : 'a => Js.Promise.t (array 'b) = "stream-to-array" [@@bs.module];
let toArray (stream : Node.Fs.Readable.t _ 'data) : Js.Promise.t (array 'data)
    => _toArray (Node.Fs.Readable.unbox stream);