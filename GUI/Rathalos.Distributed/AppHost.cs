using Projects;

var builder = DistributedApplication.CreateBuilder(args);
var db = builder.AddPostgres("rathalos")
    .WithLifetime(ContainerLifetime.Persistent)
    .WithDataVolume()
    .AddDatabase("rathalos-world");

var world = builder.AddProject<Rathalos_ConsoleUI_World>("world")
    .WithExternalHttpEndpoints()
    .WithHttpHealthCheck("/health")
    .WithReference(db);

builder.Build().Run();
