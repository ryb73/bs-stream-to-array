external _toArray : 'a => Js.Promise.t (array 'b) = "stream-to-array" [@@bs.module];
let toArray (stream : Node.Fs.Readable.t _ ('a)) : Js.Promise.t (array 'a)
    => _toArray (Node.Fs.Readable.unbox stream);