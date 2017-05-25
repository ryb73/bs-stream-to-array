open Js.Promise;
open Node.Fs;

module CsvFormatter = FastCsv.Format({
    type t = Js.t {. one: string, two: string };
});

FileWriteStream.create "out.csv" Js.undefined (fun fileStream => {
    CsvFormatter.create Js.undefined (fun csvStream => {
        CsvFormatter.pipe csvStream (FileWriteStream.writeable fileStream);
        CsvFormatter.write csvStream { "one": "ok", "two": "hey" };
        CsvFormatter.write csvStream { "one": "two", "two": "three" };
        /*ignore (Js.Exn.raiseError "This is an error");*/

        resolve ();
    });
})
    |> then_ (fun _ => {
        Js.log "after write";

        let fileStream = FileReadStream.create "out.csv" Js.undefined;
        let csvStream = FastCsv.parse ();

        FileReadStream.pipe fileStream (FastCsv.Parse.writeable csvStream);

        StreamToArray.toArray (FastCsv.Parse.readable csvStream)
            |> then_ (fun v => {
                Js.log "reading";
                Js.log (v.(0).(0) ^ "lolol");
                resolve ();
            })
            |> catch (fun err => {
                Js.log "error:";
                Js.log err;
                resolve ();
            });

        resolve ();
    })
    |> catch (fun err => {
        Js.log "caught an error:";
        Js.log err;
        resolve ();
    });
